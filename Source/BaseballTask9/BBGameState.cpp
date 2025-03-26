// 게임의 전체 상태(정답, 기회 수 관리 등)를 담당하는 클래스입니다.

#include "BBGameState.h"
#include "GameHelper.h"
#include "BBPlayerController.h"
#include "EngineUtils.h"

void ABBGameState::BeginPlay()
{
	Super::BeginPlay();

	// 게임이 시작될 때 바로 초기화
	StartGame();
}

void ABBGameState::StartGame()
{
	// 중복되지 않는 3자리 정답 생성 (1~9 사이)
	Answer = UGameHelper::GenerateRandomNumber();

	// 호스트와 게스트의 기회 수를 초기화
	HostChanceCount = InitalChanceCount;
	GuestChanceCount = InitalChanceCount;
}

void ABBGameState::JudgeResult(const FString& Msg, int32 Id)
{
	// 만약 Id == 0인 경우 호스트, 그렇지 않으면 게스트로 판단
	// 메시지(예: "/123"에서 123)를 정답과 비교
	FString Result = UGameHelper::CheckGuess(Msg, Answer);
	FString Name = TEXT("");

	// 만약 이미 해당 플레이어의 기회가 0이면, 더 이상 진행할 수 없음
	if ((Id == 0 && HostChanceCount == 0) || (Id != 0 && GuestChanceCount == 0))
	{
		for (ABBPlayerController* PC : TActorRange<ABBPlayerController>(GetWorld()))
		{
			PC->SendMsgToClient_C(TEXT("기회를 이미 모두 소진했어!"));
		}
		return;
	}

	// 플레이어 구분용 태그
	if (Id == 0)
	{
		Name = TEXT("Host : ");
		HostChanceCount--;
	}
	else
	{
		Name = TEXT("Guest : ");
		GuestChanceCount--;
	}

	// 모든 클라이언트에게 결과 전송
	for (ABBPlayerController* PC : TActorRange<ABBPlayerController>(GetWorld()))
	{
		PC->SendMsgToClient_C(Name + Result);
	}

	// 결과 문자열이 "정답입니다!"로 끝난다면 => 3 스트라이크
	if (Result.EndsWith(TEXT("정답입니다!")))
	{
		// 승리 메시지를 띄울 수도 있지만, 여기서는 바로 게임을 리셋
		for (ABBPlayerController* PC : TActorRange<ABBPlayerController>(GetWorld()))
		{
			if (Id == 0)
			{
				PC->SendMsgToClient_C(TEXT("Host Won!! 다시 게임이 시작됐다."));
			}
			else
			{
				PC->SendMsgToClient_C(TEXT("Guest Won!! 다시 게임이 시작됐다."));
			}
		}
		StartGame();
		return;
	}

	// 만약 현재 플레이어가 아웃(유효하지 않은 입력 포함)이라면, 다른 플레이어가 승리하는 규칙을 적용할 수 있음
	// 여기서는 단순히 "아웃"이라고 해도 게임을 계속 진행하는 로직으로 되어 있으므로,
	// 필요하다면 아래에서 다른 로직(상대방 승리 처리)을 추가할 수 있음

	// 두 플레이어가 모두 3회 사용했는데도 3S가 없으면 무승부
	if (HostChanceCount == 0 && GuestChanceCount == 0)
	{
		for (ABBPlayerController* PC : TActorRange<ABBPlayerController>(GetWorld()))
		{
			PC->SendMsgToClient_C(TEXT("무승부군. 다시 게임을 시작하지"));
		}
		StartGame();
	}
}

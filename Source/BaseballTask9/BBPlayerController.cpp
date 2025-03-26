// 각 플레이어(Host, Guest)마다 생기는 컨트롤러 클래스
// 클라이언트 전용 UI 생성과 서버 RPC를 통해 GameState에 입력을 전달하는 역할을 함

#include "BBPlayerController.h"
#include "InGameWidget.h"
#include "ResultData.h"
#include "BBGameState.h"
#include "Components/ListView.h"
#include "Kismet/GameplayStatics.h"

void ABBPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// 로컬 플레이어(클라이언트)인 경우에만 위젯 생성
	if (!IsLocalController())
	{
		return;
	}

	// 위젯 클래스를 에디터에서 세팅한 뒤, 인스턴스 생성
	check(WidgetClass);
	WidgetInstance = CreateWidget<UInGameWidget>(this, WidgetClass);
	check(WidgetInstance);

	// 생성된 위젯을 화면(뷰포트)에 표시
	WidgetInstance->AddToViewport();
}

void ABBPlayerController::SendMsgToClient_C_Implementation(const FString& Msg)
{
	// 서버가 보내주는 결과 문자열을 수신해 UI에 표시
	UResultData* Data = NewObject<UResultData>();
	Data->ResultString = Msg;

	WidgetInstance->ResultView->AddItem(Data);
	WidgetInstance->ResultView->SetScrollOffset(9999);  // 스크롤을 맨 아래로
}

void ABBPlayerController::SendMsgToServer_S_Implementation(const FString& Msg, int32 Id)
{
	// 서버에 연결된 GameState를 가져와서, 입력한 숫자 Msg와 ID(Host=0, Guest=1)를 넘겨줌
	ABBGameState* GS = CastChecked<ABBGameState>(UGameplayStatics::GetGameState(GetWorld()));
	GS->JudgeResult(Msg, Id);
}

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "BBGameState.generated.h"

/**
 * 전체 게임의 상태를 관리하는 클래스입니다.
 * 여기서 정답, 시도 횟수, 승패 판정 로직 등을 다룹니다.
 */
UCLASS()
class BASEBALLTASK9_API ABBGameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	// 게임(정답 및 기회 수) 초기화
	void StartGame();

	// 메시지와 플레이어 ID를 받아 판정 로직을 수행
	void JudgeResult(const FString& Msg, int32 Id);

public:
	// 플레이어 당 최대 시도 횟수
	int32 InitalChanceCount = 3;

	// 호스트와 게스트의 남은 시도 횟수
	int32 HostChanceCount = 3;
	int32 GuestChanceCount = 3;

	// 정답(중복 없는 3자리)
	FString Answer = TEXT("");
};

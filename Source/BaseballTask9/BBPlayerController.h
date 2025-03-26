#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BBPlayerController.generated.h"

class UInGameWidget;

/**
 * 플레이어 컨트롤러: 각 플레이어별 입력 및 UI를 담당하고,
 * 서버와 메시지를 주고받는 역할을 한다.
 */
UCLASS()
class BASEBALLTASK9_API ABBPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	// 게임 시작 시 클라이언트에서 위젯 생성
	virtual void BeginPlay() override;

public:
	// 서버에서 클라이언트로 메시지를 보내는 함수
	UFUNCTION(Client, Reliable)
	void SendMsgToClient_C(const FString& Msg);

	// 클라이언트에서 서버로 숫자 입력을 보내는 함수
	UFUNCTION(Server, Reliable)
	void SendMsgToServer_S(const FString& Msg, int32 Id);

protected:
	// 블루프린트에서 설정할 위젯 클래스
	UPROPERTY(EditAnywhere)
	TSubclassOf<UInGameWidget> WidgetClass;

	// 실제로 생성된 위젯 인스턴스
	UPROPERTY(EditAnywhere)
	TObjectPtr<UInGameWidget> WidgetInstance;
};

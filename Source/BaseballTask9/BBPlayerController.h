#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BBPlayerController.generated.h"

class UInGameWidget;

/**
 * �÷��̾� ��Ʈ�ѷ�: �� �÷��̾ �Է� �� UI�� ����ϰ�,
 * ������ �޽����� �ְ�޴� ������ �Ѵ�.
 */
UCLASS()
class BASEBALLTASK9_API ABBPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	// ���� ���� �� Ŭ���̾�Ʈ���� ���� ����
	virtual void BeginPlay() override;

public:
	// �������� Ŭ���̾�Ʈ�� �޽����� ������ �Լ�
	UFUNCTION(Client, Reliable)
	void SendMsgToClient_C(const FString& Msg);

	// Ŭ���̾�Ʈ���� ������ ���� �Է��� ������ �Լ�
	UFUNCTION(Server, Reliable)
	void SendMsgToServer_S(const FString& Msg, int32 Id);

protected:
	// �������Ʈ���� ������ ���� Ŭ����
	UPROPERTY(EditAnywhere)
	TSubclassOf<UInGameWidget> WidgetClass;

	// ������ ������ ���� �ν��Ͻ�
	UPROPERTY(EditAnywhere)
	TObjectPtr<UInGameWidget> WidgetInstance;
};

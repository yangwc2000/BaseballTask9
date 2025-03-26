#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "BBGameState.generated.h"

/**
 * ��ü ������ ���¸� �����ϴ� Ŭ�����Դϴ�.
 * ���⼭ ����, �õ� Ƚ��, ���� ���� ���� ���� �ٷ�ϴ�.
 */
UCLASS()
class BASEBALLTASK9_API ABBGameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	// ����(���� �� ��ȸ ��) �ʱ�ȭ
	void StartGame();

	// �޽����� �÷��̾� ID�� �޾� ���� ������ ����
	void JudgeResult(const FString& Msg, int32 Id);

public:
	// �÷��̾� �� �ִ� �õ� Ƚ��
	int32 InitalChanceCount = 3;

	// ȣ��Ʈ�� �Խ�Ʈ�� ���� �õ� Ƚ��
	int32 HostChanceCount = 3;
	int32 GuestChanceCount = 3;

	// ����(�ߺ� ���� 3�ڸ�)
	FString Answer = TEXT("");
};

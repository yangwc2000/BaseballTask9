#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameHelper.generated.h"

/**
 * �߱� ������ �ٽ� ����:
 *  - ��ġ�� �ʴ� ����(3�ڸ�) ����
 *  - �Է°��� ���䰪�� ���Ͽ� S/B/�ƿ�/���� ����
 */
UCLASS()
class BASEBALLTASK9_API UGameHelper : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	// �ߺ����� �ʴ� 1~9 ���� 3�ڸ� ���� ����
	static FString GenerateRandomNumber();

	// Guess(����� �Է�)�� ������ ���� S/B/�ƿ�/���� ���� ���ڿ��� ��ȯ
	static FString CheckGuess(const FString& Guess, const FString& Answer);
};

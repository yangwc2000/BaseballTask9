#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ResultData.generated.h"

/**
 * ListView � ǥ���� ���ڿ� �����͸� ��� Ŭ����
 */
UCLASS()
class BASEBALLTASK9_API UResultData : public UObject
{
	GENERATED_BODY()

public:
	// �޽��� �����
	FString ResultString;
};

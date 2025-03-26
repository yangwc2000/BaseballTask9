#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ResultData.generated.h"

/**
 * ListView 등에 표시할 문자열 데이터를 담는 클래스
 */
UCLASS()
class BASEBALLTASK9_API UResultData : public UObject
{
	GENERATED_BODY()

public:
	// 메시지 저장용
	FString ResultString;
};

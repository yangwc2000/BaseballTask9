#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameHelper.generated.h"

/**
 * 야구 게임의 핵심 로직:
 *  - 겹치지 않는 난수(3자리) 생성
 *  - 입력값과 정답값을 비교하여 S/B/아웃/정답 판정
 */
UCLASS()
class BASEBALLTASK9_API UGameHelper : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	// 중복되지 않는 1~9 범위 3자리 난수 생성
	static FString GenerateRandomNumber();

	// Guess(사용자 입력)과 정답을 비교해 S/B/아웃/정답 판정 문자열을 반환
	static FString CheckGuess(const FString& Guess, const FString& Answer);
};

// 게임의 핵심 로직(난수 생성, 입력 판정)을 담은 BlueprintFunctionLibrary

#include "GameHelper.h"
#include "Algo/RandomShuffle.h"

FString UGameHelper::GenerateRandomNumber()
{
	// 1~9 숫자를 배열에 담은 후 무작위로 섞어서 앞의 3개를 붙임
	TArray<int32> NumberList{ 1,2,3,4,5,6,7,8,9 };
	Algo::RandomShuffle(NumberList);

	FString NewRandomNumber;
	for (int i = 0; i < 3; ++i)
	{
		NewRandomNumber += FString::FromInt(NumberList[i]);
	}

	return NewRandomNumber;
}

FString UGameHelper::CheckGuess(const FString& Guess, const FString& Answer)
{
	// 3자리가 아니거나 숫자가 아니면 아웃 처리 (규칙상 유효하지 않은 입력)
	if (Guess.Len() != 3 || !Guess.IsNumeric())
	{
		return Guess + TEXT(" : 아웃 (유효하지 않은 입력)");
	}

	// 0이 포함되거나 중복 숫자가 있으면 아웃
	TSet<TCHAR> UsedChars;
	for (int i = 0; i < Guess.Len(); i++)
	{
		if (Guess[i] == '0')
		{
			return Guess + TEXT(" : 아웃 (0은 허용 안 됨)");
		}
		if (UsedChars.Contains(Guess[i]))
		{
			return Guess + TEXT(" : 아웃 (중복 숫자)");
		}
		UsedChars.Add(Guess[i]);
	}

	// 이제 정상 입력이면 S/B 판정
	int32 Strikes = 0, Balls = 0;
	for (int32 i = 0; i < 3; i++)
	{
		int32 FoundIndex = -1;
		if (Guess.FindChar(Answer[i], FoundIndex))
		{
			// 위치까지 같으면 스트라이크
			if (Guess[i] == Answer[i])
			{
				Strikes++;
			}
			// 숫자만 같고 위치 다르면 볼
			else
			{
				Balls++;
			}
		}
	}

	// 스트라이크와 볼에 모두 해당 안 되면 아웃. (즉 3아웃)
	int32 OutCount = 3 - Strikes - Balls;
	if (OutCount == 3)
	{
		return Guess + TEXT(" : 아웃");
	}

	// 3 스트라이크면 정답
	if (Strikes == 3)
	{
		return Guess + TEXT(" : 3 스트라이크 정답입니다!");
	}

	// 여기까지 왔다면 스트라이크/볼 조합
	return Guess + FString::Printf(TEXT(" : %d 스트라이크 / %d 볼"), Strikes, Balls);
}

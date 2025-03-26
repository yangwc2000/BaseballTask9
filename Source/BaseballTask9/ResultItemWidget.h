// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/IUserObjectListEntry.h"

#include "ResultItemWidget.generated.h"

/**
 * 
 */
UCLASS()
class BASEBALLTASK9_API UResultItemWidget : public UUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()

protected:
	virtual void NativeOnListItemObjectSet(UObject* ListItemObject) override;		//리스트에 새로운 아이템 데이터가 설정될 때 자동으로 호출되는 함수

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UTextBlock> ItemText;		//블루프린트에서 디자인한 TextBlock 위젯을 C++에서 바인딩(결과 메시지를 이 TextBlock에 출력함)

};

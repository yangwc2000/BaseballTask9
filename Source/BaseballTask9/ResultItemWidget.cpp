// Fill out your copyright notice in the Description page of Project Settings.


#include "ResultItemWidget.h"
#include "ResultData.h"

#include "Components/TextBlock.h"

void UResultItemWidget::NativeOnListItemObjectSet(UObject* ListItemObject)		// 리스트 아이템 객체가 세팅될 때 호출되는 함수(ListView에 항목이 추가될 때마다 실행됨)
{
	IUserObjectListEntry::NativeOnListItemObjectSet(ListItemObject);		// 부모 클래스의 기본 처리 실행 (안전한 위젯 초기화를 위해 호출 필수)

	UResultData* Data = CastChecked<UResultData>(ListItemObject);		// 전달받은 객체(ListItemObject)를 UResultData 타입으로 강제 캐스팅

	ItemText->SetText(FText::FromString(Data->ResultString));		// Data에 담긴 결과 문자열을 가져와 TextBlock(ItemText)에 표시
}

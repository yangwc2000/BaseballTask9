// Fill out your copyright notice in the Description page of Project Settings.


#include "ResultItemWidget.h"
#include "ResultData.h"

#include "Components/TextBlock.h"

void UResultItemWidget::NativeOnListItemObjectSet(UObject* ListItemObject)		// ����Ʈ ������ ��ü�� ���õ� �� ȣ��Ǵ� �Լ�(ListView�� �׸��� �߰��� ������ �����)
{
	IUserObjectListEntry::NativeOnListItemObjectSet(ListItemObject);		// �θ� Ŭ������ �⺻ ó�� ���� (������ ���� �ʱ�ȭ�� ���� ȣ�� �ʼ�)

	UResultData* Data = CastChecked<UResultData>(ListItemObject);		// ���޹��� ��ü(ListItemObject)�� UResultData Ÿ������ ���� ĳ����

	ItemText->SetText(FText::FromString(Data->ResultString));		// Data�� ��� ��� ���ڿ��� ������ TextBlock(ItemText)�� ǥ��
}

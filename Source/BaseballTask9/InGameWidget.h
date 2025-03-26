// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InGameWidget.generated.h"

/**
 * 
 */
UCLASS()
class BASEBALLTASK9_API UInGameWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:

	virtual void NativeConstruct() override;		//������ ������ �� ȣ��Ǵ� �Լ� (BeginPlay ����)

public:

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<class UEditableTextBox> ChatBox;		//UMG �������Ʈ �󿡼� "ChatBox"��� �̸��� �ؽ�Ʈ �ڽ��� ���ε�(�Է�â)

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UListView> ResultView;		//"ResultView"��� �̸��� ����Ʈ �� ���� ���ε�(��� �޽����� ������� ����ϴ� �뵵)

private:
	UFUNCTION()
	void OnCommitted(const FText& Text, ETextCommit::Type CommitMethod);		// �ؽ�Ʈ �Է��� Ȯ���Ǿ��� �� ȣ��Ǵ� �Լ� (�Է��� ������ ������ �����ϱ� ���� Ʈ����)

};

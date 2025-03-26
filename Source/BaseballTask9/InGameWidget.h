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

	virtual void NativeConstruct() override;		//위젯이 생성될 때 호출되는 함수 (BeginPlay 역할)

public:

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<class UEditableTextBox> ChatBox;		//UMG 블루프린트 상에서 "ChatBox"라는 이름의 텍스트 박스를 바인딩(입력창)

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UListView> ResultView;		//"ResultView"라는 이름의 리스트 뷰 위젯 바인딩(결과 메시지를 순서대로 출력하는 용도)

private:
	UFUNCTION()
	void OnCommitted(const FText& Text, ETextCommit::Type CommitMethod);		// 텍스트 입력이 확정되었을 때 호출되는 함수 (입력한 내용을 서버로 전송하기 위한 트리거)

};

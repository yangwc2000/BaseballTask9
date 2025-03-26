// Fill out your copyright notice in the Description page of Project Settings.


#include "InGameWidget.h"

#include "BBPlayerController.h"

#include "Components/EditableTextBox.h"
#include "Components/ListView.h"
#include "Kismet/GameplayStatics.h"


void UInGameWidget::NativeConstruct()
{
	Super::NativeConstruct();		//부모 클래스의 초기화 로직 실행 (기본 위젯 생성)

	ChatBox->OnTextCommitted.AddDynamic(this, &UInGameWidget::OnCommitted);	//텍스트 박스(ChatBox)에 '입력 확정' 이벤트 연결 사용자가 엔터를 누르거나 포커스를 잃었을 때 호출됨
}

void UInGameWidget::OnCommitted(const FText& Text, ETextCommit::Type CommitMethod)
{
	if (CommitMethod == ETextCommit::Type::OnEnter)		//입력 확정 방식이 '엔터키'일 경우에만 처리
	{
		ABBPlayerController* PC = CastChecked<ABBPlayerController>(UGameplayStatics::GetPlayerController(this, 0));		// 현재 로컬 플레이어 컨트롤러를 ABBPlayerController로 캐스팅

		int32 Id = (PC->HasAuthority()) ? 0 : 1;		//컨트롤러가 서버 권한이면 Id = 0 (Host), 아니면 1 (Guest)
		PC->SendMsgToServer_S(Text.ToString(), Id);		//서버에게 입력된 텍스트와 Id를 전송 → 서버가 판단
	}
}

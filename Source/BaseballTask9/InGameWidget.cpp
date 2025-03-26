// Fill out your copyright notice in the Description page of Project Settings.


#include "InGameWidget.h"

#include "BBPlayerController.h"

#include "Components/EditableTextBox.h"
#include "Components/ListView.h"
#include "Kismet/GameplayStatics.h"


void UInGameWidget::NativeConstruct()
{
	Super::NativeConstruct();		//�θ� Ŭ������ �ʱ�ȭ ���� ���� (�⺻ ���� ����)

	ChatBox->OnTextCommitted.AddDynamic(this, &UInGameWidget::OnCommitted);	//�ؽ�Ʈ �ڽ�(ChatBox)�� '�Է� Ȯ��' �̺�Ʈ ���� ����ڰ� ���͸� �����ų� ��Ŀ���� �Ҿ��� �� ȣ���
}

void UInGameWidget::OnCommitted(const FText& Text, ETextCommit::Type CommitMethod)
{
	if (CommitMethod == ETextCommit::Type::OnEnter)		//�Է� Ȯ�� ����� '����Ű'�� ��쿡�� ó��
	{
		ABBPlayerController* PC = CastChecked<ABBPlayerController>(UGameplayStatics::GetPlayerController(this, 0));		// ���� ���� �÷��̾� ��Ʈ�ѷ��� ABBPlayerController�� ĳ����

		int32 Id = (PC->HasAuthority()) ? 0 : 1;		//��Ʈ�ѷ��� ���� �����̸� Id = 0 (Host), �ƴϸ� 1 (Guest)
		PC->SendMsgToServer_S(Text.ToString(), Id);		//�������� �Էµ� �ؽ�Ʈ�� Id�� ���� �� ������ �Ǵ�
	}
}

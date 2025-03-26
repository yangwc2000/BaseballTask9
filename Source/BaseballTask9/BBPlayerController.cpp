// �� �÷��̾�(Host, Guest)���� ����� ��Ʈ�ѷ� Ŭ����
// Ŭ���̾�Ʈ ���� UI ������ ���� RPC�� ���� GameState�� �Է��� �����ϴ� ������ ��

#include "BBPlayerController.h"
#include "InGameWidget.h"
#include "ResultData.h"
#include "BBGameState.h"
#include "Components/ListView.h"
#include "Kismet/GameplayStatics.h"

void ABBPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// ���� �÷��̾�(Ŭ���̾�Ʈ)�� ��쿡�� ���� ����
	if (!IsLocalController())
	{
		return;
	}

	// ���� Ŭ������ �����Ϳ��� ������ ��, �ν��Ͻ� ����
	check(WidgetClass);
	WidgetInstance = CreateWidget<UInGameWidget>(this, WidgetClass);
	check(WidgetInstance);

	// ������ ������ ȭ��(����Ʈ)�� ǥ��
	WidgetInstance->AddToViewport();
}

void ABBPlayerController::SendMsgToClient_C_Implementation(const FString& Msg)
{
	// ������ �����ִ� ��� ���ڿ��� ������ UI�� ǥ��
	UResultData* Data = NewObject<UResultData>();
	Data->ResultString = Msg;

	WidgetInstance->ResultView->AddItem(Data);
	WidgetInstance->ResultView->SetScrollOffset(9999);  // ��ũ���� �� �Ʒ���
}

void ABBPlayerController::SendMsgToServer_S_Implementation(const FString& Msg, int32 Id)
{
	// ������ ����� GameState�� �����ͼ�, �Է��� ���� Msg�� ID(Host=0, Guest=1)�� �Ѱ���
	ABBGameState* GS = CastChecked<ABBGameState>(UGameplayStatics::GetGameState(GetWorld()));
	GS->JudgeResult(Msg, Id);
}

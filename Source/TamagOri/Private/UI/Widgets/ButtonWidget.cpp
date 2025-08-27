#include "TamagOri/Public/UI/Widgets/ButtonWidget.h"

#include "Components/Button.h"
#include "Components/TextBlock.h"

void UButtonWidget::NativePreConstruct()
{
	Super::NativePreConstruct();

	ensureMsgf(IsValid(Button), TEXT("Button widget not binded"));
	if (IsValid(Button))
	{
		Button->SetBackgroundColor(ButtonColor);
		ButtonText->SetText(InternalText);
	}
	
}

void UButtonWidget::NativeConstruct()
{
	Super::NativeConstruct();

	ensureMsgf(IsValid(Button), TEXT("Button widget not binded"));
	if (!IsValid(Button)){return;}
	Button->OnClicked.AddDynamic(this, &UButtonWidget::OnClick);
}

void UButtonWidget::OnClick()
{
	OnButtonClickedDelegate.Broadcast();
}

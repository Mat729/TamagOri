#include "TamagOri/Public/UI/Widgets/ButtonWidget.h"

#include "Components/Button.h"
#include "Components/TextBlock.h"

void UButtonWidget::NativePreConstruct()
{
	Super::NativePreConstruct();

	if (Button)
	{
		Button->SetBackgroundColor(ButtonColor);
		ButtonText->SetText(InternalText);
	}
	
}

void UButtonWidget::NativeConstruct()
{
	Super::NativeConstruct();

	Button->OnClicked.AddDynamic(this, &UButtonWidget::OnClick);
}

void UButtonWidget::OnClick()
{
	OnButtonClickedDelegate.Broadcast();
}

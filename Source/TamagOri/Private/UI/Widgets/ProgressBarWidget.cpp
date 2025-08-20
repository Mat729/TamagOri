#include "TamagOri/Public/UI/Widgets/ProgressBarWidget.h"

#include "Components/ProgressBar.h"
#include "UI/Widgets/ButtonWidget.h"

void UProgressBarWidget::NativePreConstruct()
{
	Super::NativePreConstruct();
	ProgressBar->SetPercent(BarMaxPercent);
	ProgressBar->SetFillColorAndOpacity(BarColor);
}

void UProgressBarWidget::NativeConstruct()
{
	Super::NativeConstruct();
	ButtonWidget->OnButtonClickedDelegate.AddDynamic(this, &UProgressBarWidget::IncreaseBarPercent);
}

void UProgressBarWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	DecreaseBarWithTime(InDeltaTime);
}

void UProgressBarWidget::DecreaseBarWithTime(float InDeltaTime)
{
	CurrentBarPercent -= BarMaxPercent * InDeltaTime;

	NormalizeBarPercent(CurrentBarPercent);
	
	if (CurrentBarPercent < 4.0)
	{
		UE_LOG(LogTemp, Error, TEXT("Triggered"));
	}
}

void UProgressBarWidget::NormalizeBarPercent(float InCurrentBarPercent)
{
	CurrentBarPercent = (InCurrentBarPercent / BarMaxPercent) * 100;
}

void UProgressBarWidget::IncreaseBarPercent()
{
	CurrentBarPercent += ValueToAddOnButtonClick;
}
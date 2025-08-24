#include "TamagOri/Public/UI/Widgets/ProgressBarWidget.h"

#include "Components/ProgressBar.h"
#include "UI/TamagOriPage.h"
#include "UI/Widgets/ButtonWidget.h"

void UProgressBarWidget::NativePreConstruct()
{
	Super::NativePreConstruct();
	
	if(IsValid(ProgressBar))
	{
		CurrentBarPercent = BarMaxPercent;
		NormalizedBarPercent = CurrentBarPercent / BarMaxPercent;
		
		ProgressBar->SetPercent(NormalizedBarPercent);
		ProgressBar->SetFillColorAndOpacity(BarColor);
	}

}

void UProgressBarWidget::NativeConstruct()
{
	Super::NativeConstruct();
	
	ensureMsgf(IsValid(ButtonWidget), TEXT("ButtonWidget not referenced"));
	if(!IsValid(ButtonWidget)){return;}
	ButtonWidget->OnButtonClickedDelegate.AddDynamic(this, &UProgressBarWidget::IncreaseBarPercent);
}

void UProgressBarWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	if(!bCanTick){return;}

	DecreaseBarWithTime(InDeltaTime);
	OriGrowth(InDeltaTime);
}

void UProgressBarWidget::OriGrowth(float InDeltaTime)
{
	TimePassed +=InDeltaTime ;
	if (TimePassed > 3.0)
	{
		OnStateChanged.Broadcast(EOriStates::Adult);
	}
}

void UProgressBarWidget::DecreaseBarWithTime(float InDeltaTime)
{
	CurrentBarPercent -= DecreseBarRate * InDeltaTime;
	NormalizeAndRoundPercent(CurrentBarPercent);
	UE_LOG(LogTemp, Warning, TEXT("Bar percentage: %f"),PercentRoundedToFloat);

	if (NormalizedBarPercent >= .4f && bHasTriggeredChange)
	{
		OnStateChanged.Broadcast(EOriStates::Adult);
		bHasTriggeredChange = false;
	}
	
	
}

void UProgressBarWidget::NormalizeAndRoundPercent(float InCurrentBarPercent)
{
	NormalizedBarPercent = InCurrentBarPercent / BarMaxPercent;
	ensureMsgf(ProgressBar, TEXT("Progress bar not referenced"));
	if (!IsValid(ProgressBar)){return;}
	ProgressBar->SetPercent(NormalizedBarPercent);
	if (NormalizedBarPercent < .4f && !bHasTriggeredChange)
	{
		UE_LOG(LogTemp, Error, TEXT("Triggered"));
		OnStateChanged.Broadcast(OriStateToTrigger);
		bHasTriggeredChange = true;
	}
	if (NormalizedBarPercent == 0.f)
	{
		OnStateChanged.Broadcast(EOriStates::Dead);
	}
	PercentRoundedToFloat= FMath::RoundToFloat(NormalizedBarPercent *10.f)/ 10.f;
}


void UProgressBarWidget::IncreaseBarPercent()
{
	CurrentBarPercent += ValueToAddOnButtonClick;
	UE_LOG(LogTemp, Warning, TEXT("Stat value added"));
}

void UProgressBarWidget::StopTicking()
{
	bCanTick = false;
}

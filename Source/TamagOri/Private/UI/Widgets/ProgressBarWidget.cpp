#include "TamagOri/Public/UI/Widgets/ProgressBarWidget.h"

#include "Components/ProgressBar.h"
#include "UI/TamagOriPage.h"
#include "UI/Widgets/ButtonWidget.h"

void UProgressBarWidget::NativePreConstruct()
{
	Super::NativePreConstruct();

	ensureMsgf(IsValid(ProgressBar), TEXT("ProgressBar widget not binded"));
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
	if (TimePassed > 5.0 && !bIsOriGrwon)
	{
		OnStateChangedDelegate.Broadcast(EOriStates::Adult);
		bIsOriGrwon = true;
	}
}

void UProgressBarWidget::DecreaseBarWithTime(float InDeltaTime)
{
	CurrentBarPercent -= DecreseBarRate * InDeltaTime;
	NormalizeAndRoundPercent(CurrentBarPercent);

	if (NormalizedBarPercent < .4f && !bHasTriggeredChange)
	{
		UE_LOG(LogTemp, Warning, TEXT("Broadcasting state: %d"), (int32)OriStateToTrigger);
		OnStateChangedDelegate.Broadcast(OriStateToTrigger);
		UE_LOG(LogTemp, Warning, TEXT("Finished broadcast"));
		bHasTriggeredChange = true;
	}
	if (PercentRoundedToFloat >= .4f && bHasTriggeredChange)
	{
		UE_LOG(LogTemp, Error, TEXT("Triggered returned back"));
		OnStateChangedDelegate.Broadcast(EOriStates::Adult);
		bHasTriggeredChange = false;
	}
	if (NormalizedBarPercent <= KINDA_SMALL_NUMBER)
	{
		UE_LOG(LogTemp, Error, TEXT("Triggered death"));
		OnStateChangedDelegate.Broadcast(EOriStates::Dead);
	}
	
}

void UProgressBarWidget::NormalizeAndRoundPercent(float InCurrentBarPercent)
{
	NormalizedBarPercent = InCurrentBarPercent / BarMaxPercent;
	ensureMsgf(ProgressBar, TEXT("Progress bar not referenced"));
	if (!IsValid(ProgressBar)){return;}
	ProgressBar->SetPercent(NormalizedBarPercent);
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

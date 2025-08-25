#include "UI/TamagOriPage.h"

#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "UI/Widgets/ButtonWidget.h"
#include "UI/Widgets/OriDeathWidget.h"
#include "UI/Widgets/ProgressBarWidget.h"

void UTamagOriPage::NativePreConstruct()
{
	Super::NativePreConstruct();
	ChangeState(EOriStates::Young);
	OriDeathWidget->SetVisibility(ESlateVisibility::Collapsed);
}

void UTamagOriPage::NativeConstruct()
{
	Super::NativeConstruct();

	ensureMsgf(IsValid(HungerBar) && IsValid(ThirstBar) && IsValid(PoopBar),TEXT("Bindings are not correct"));
	if (!IsValid(HungerBar) || !IsValid(ThirstBar) || !IsValid(PoopBar)) {return;}
	HungerBar->OnStateChangedDelegate.AddDynamic(this, &UTamagOriPage::ChangeState);
	ThirstBar->OnStateChangedDelegate.AddDynamic(this, &UTamagOriPage::ChangeState);
	PoopBar->OnStateChangedDelegate.AddDynamic(this, &UTamagOriPage::ChangeState);
}

void UTamagOriPage::ChangeState(EOriStates OriState)
{
	switch (OriState)
	{
		case EOriStates::Young:
			UE_LOG(LogTemp, Warning, TEXT("Switch -> Young"));
			YoungState();
			break;
		case EOriStates::Adult:
			UE_LOG(LogTemp, Warning, TEXT("Switch -> Adult"));
			AdultState();
			break;
		case EOriStates::Hungry:
			UE_LOG(LogTemp, Warning, TEXT("Switch -> Hungry"));
			HungryState();
			break;
		case EOriStates::Thirsty:
			UE_LOG(LogTemp, Warning, TEXT("Switch -> Thirsty"));
			ThirstState();
			break;
		case EOriStates::Poopy:
			UE_LOG(LogTemp, Warning, TEXT("Switch -> Poopy"));
			PoopyState();
			break;
		case EOriStates::Dead:
			UE_LOG(LogTemp, Warning, TEXT("Switch -> Dead"));
			DeadState();
			break;
		default:
			UE_LOG(LogTemp, Error, TEXT("Unhandled state! %d"), (int32)OriState);
			break;
	}
}

void UTamagOriPage::YoungState()
{
	OriStateTextBlock->SetText(FText::FromString("Ori is a puppy"));
	SetImage(YoungTexture);
}

void UTamagOriPage::AdultState()
{
	OriStateTextBlock->SetText(FText::FromString("Ori has grown up"));
	SetImage(AdultTexture);
}

void UTamagOriPage::HungryState()
{
	OriStateTextBlock->SetText(FText::FromString("Ori wants to be fed!"));
	SetImage(HungryTexture);
}

void UTamagOriPage::ThirstState()
{
	OriStateTextBlock->SetText(FText::FromString("Ori wants to drink!"));
	SetImage(ThirstyTexture);
}

void UTamagOriPage::PoopyState()
{
	OriStateTextBlock->SetText(FText::FromString("Ori needs to poop!"));
	SetImage(PoopyTexture);
}

void UTamagOriPage::DeadState()
{
	OriStateTextBlock->SetText(FText::FromString("Ori is dead!"));
	SetImage(DeadTexture);
	HungerBar->StopTicking();
	ThirstBar->StopTicking();
	PoopBar->StopTicking();
	HungerButton->SetIsEnabled(false);
	ThirstButton->SetIsEnabled(false);
	PoopButton->SetIsEnabled(false);
	OriDeathWidget->SetVisibility(ESlateVisibility::Visible);
}

void UTamagOriPage::SetImage(UTexture2D* OriTexture)
{
	ensureMsgf(IsValid(OriTexture) && IsValid(OriImage),TEXT("Texture not found"));
	if (IsValid(OriTexture) && IsValid(OriImage))
	{
		OriImage->SetBrushFromTexture(OriTexture);
	}
}

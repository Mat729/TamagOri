#include "UI/TamagOriPage.h"

#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "UI/Widgets/ProgressBarWidget.h"

void UTamagOriPage::NativePreConstruct()
{
	Super::NativePreConstruct();
	ChangeState(EOriStates::Young);
}

void UTamagOriPage::NativeConstruct()
{
	Super::NativeConstruct();
	HungerBar->OnStateChanged.AddDynamic(this, &UTamagOriPage::ChangeState);
	ThirstBar->OnStateChanged.AddDynamic(this, &UTamagOriPage::ChangeState);
	PoopBar->OnStateChanged.AddDynamic(this, &UTamagOriPage::ChangeState);
}

void UTamagOriPage::ChangeState(EOriStates OriState)
{
	switch (OriState)
	{
		case EOriStates::Young:
			YoungState();
			break;
		case EOriStates::Adult:
			AdultState();
			break;
		case EOriStates::Hungry:
			HungryState();
			break;
		case EOriStates::Thirsty:
			ThirstState();
			break;
		case EOriStates::Poopy:
			PoopyState();
			break;
		case EOriStates::Dead:
			DeadState();
			break;
	}
}

void UTamagOriPage::YoungState()
{
	//OriStateText->SetText();//TODO settare il text al variare dello state
	SetImage(YoungTexture);
}

void UTamagOriPage::AdultState()
{
	SetImage(AdultTexture);
}

void UTamagOriPage::HungryState()
{
	SetImage(HungryTexture);
}

void UTamagOriPage::ThirstState()
{
	SetImage(ThirstyTexture);
}

void UTamagOriPage::PoopyState()
{
	SetImage(PoopyTexture);
}

void UTamagOriPage::DeadState()
{
	SetImage(DeadTexture);
	HungerBar->StopTicking();
	ThirstBar->StopTicking();
	PoopBar->StopTicking();
}

void UTamagOriPage::SetImage(UTexture2D* OriTexture)
{
	ensureMsgf(IsValid(OriTexture) && IsValid(OriImage),TEXT("Texture not found"));
	if (IsValid(OriTexture) && IsValid(OriImage))
	{
		OriImage->SetBrushFromTexture(OriTexture);
	}
}

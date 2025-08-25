#include "UI/GameHUD.h"

#include "Blueprint/WidgetBlueprintLibrary.h"
#include "UI/TamagOriPage.h"

void AGameHUD::BeginPlay()
{
	Super::BeginPlay();
	CreateWidgetAndAddToViewport();
	APlayerController* PC = GetOwningPlayerController();
	ensureMsgf(IsValid(PC),TEXT("PlayerController is not valid"));
	if (!IsValid(PC)) {return;}
	PC->SetInputMode(FInputModeUIOnly());
	PC->SetShowMouseCursor(true);
	
}

void AGameHUD::CreateWidgetAndAddToViewport()
{
	ensureMsgf(TamagOriPageClass, TEXT("Class of the widget not specified"));
	if (!IsValid(TamagOriPageClass)){return;}
	TamagOriPage = Cast<UTamagOriPage>( UWidgetBlueprintLibrary::Create(this,TamagOriPageClass,GetOwningPlayerController()));
	ensureMsgf(TamagOriPage, TEXT("Widget not created"));
	if (!IsValid(TamagOriPage)){return;}
	TamagOriPage->AddToViewport();
}

#include "UI/Widgets/OriDeathWidget.h"

#include "Kismet/GameplayStatics.h"
#include "UI/Widgets/ButtonWidget.h"

void UOriDeathWidget::NativeConstruct()
{
	Super::NativeConstruct();
	
	ensureMsgf(IsValid(RetryButton) && IsValid(QuitButton),TEXT("Delegates not binded properly"));
	if (!IsValid(RetryButton) || !IsValid(QuitButton)){return;}
	RetryButton->OnButtonClickedDelegate.AddDynamic(this, &UOriDeathWidget::OnClickRetry);
	QuitButton->OnButtonClickedDelegate.AddDynamic(this, &UOriDeathWidget::OnClickQuit);
}

void UOriDeathWidget::OnClickRetry()
{
	UE_LOG(LogTemp,Display,TEXT("OnClickRetry"));
	UGameplayStatics::OpenLevel(GetWorld(), "TamagOri");
}

void UOriDeathWidget::OnClickQuit()
{
	UKismetSystemLibrary::QuitGame(GetWorld(),GetOwningPlayer(),EQuitPreference::Quit,true);
}

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TamagOriPage.generated.h"

class UOriDeathWidget;
class UImage;
class UTextBlock;
class UButtonWidget;
class UProgressBarWidget;

UENUM (BlueprintType)
enum class EOriStates : uint8
{
	Hungry  UMETA(DisplayName = "Hungry"),
	Thirsty UMETA(DisplayName = "Thirsty"),
	Poopy   UMETA(DisplayName = "Poopy"),
	Young   UMETA(DisplayName = "Young"),
	Adult   UMETA(Displayname = "Adult"),
	Dead    UMETA(DisplayName = "Dead")
};

UCLASS()
class TAMAGORI_API UTamagOriPage : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativePreConstruct() override;
	virtual void NativeConstruct() override;

private:
//--- Widgets binding start ---//
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget, AllowPrivateAccess = true), Category = "TamagOri | Personalization")
	TObjectPtr<UProgressBarWidget> HungerBar = nullptr;

	UPROPERTY(BlueprintReadWrite, meta=(BindWidget, AllowPrivateAccess = true), Category = "TamagOri | Personalization")
	TObjectPtr<UProgressBarWidget> ThirstBar = nullptr;

	UPROPERTY(BlueprintReadWrite, meta=(BindWidget, AllowPrivateAccess = true), Category = "TamagOri | Personalization")
	TObjectPtr<UProgressBarWidget> PoopBar = nullptr;

	UPROPERTY(BlueprintReadWrite, meta=(BindWidget, AllowPrivateAccess = true), Category = "TamagOri | Personalization")
	TObjectPtr<UButtonWidget> HungerButton = nullptr;

	UPROPERTY(BlueprintReadWrite, meta=(BindWidget, AllowPrivateAccess = true), Category = "TamagOri | Personalization")
	TObjectPtr<UButtonWidget> ThirstButton = nullptr;

	UPROPERTY(BlueprintReadWrite, meta=(BindWidget, AllowPrivateAccess = true), Category = "TamagOri | Personalization")
	TObjectPtr<UButtonWidget> PoopButton = nullptr;

	UPROPERTY(BlueprintReadWrite, meta=(BindWidget, AllowPrivateAccess = true), Category = "TamagOri | Personalization")
	TObjectPtr<UTextBlock> OriStateTextBlock = nullptr;

	UPROPERTY(BlueprintReadWrite, meta=(BindWidget, AllowPrivateAccess = true), Category = "TamagOri | Personalization")
	TObjectPtr<UImage> OriImage = nullptr;

	UPROPERTY(BlueprintReadWrite, meta=(BindWidget, AllowPrivateAccess = true), Category = "TamagOri | Personalization")
	TObjectPtr<UOriDeathWidget> OriDeathWidget = nullptr;
//--- Widgets binding end ---//

	
//--- State Images Setup start ---//
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(AllowPrivateAccess = true), Category = "TamagOri | State Setup")
	TObjectPtr<UTexture2D> HungryTexture = nullptr;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(AllowPrivateAccess = true), Category = "TamagOri | State Setup")
	TObjectPtr<UTexture2D> ThirstyTexture = nullptr;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(AllowPrivateAccess = true), Category = "TamagOri | State Setup")
	TObjectPtr<UTexture2D> PoopyTexture = nullptr;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(AllowPrivateAccess = true), Category = "TamagOri | State Setup")
	TObjectPtr<UTexture2D> YoungTexture = nullptr;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(AllowPrivateAccess = true), Category = "TamagOri | State Setup")
	TObjectPtr<UTexture2D> AdultTexture = nullptr;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(AllowPrivateAccess = true), Category = "TamagOri | State Setup")
	TObjectPtr<UTexture2D> DeadTexture = nullptr;
//--- State Images Setup end ---//
	
//--- State default Setup Start ---//
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = true), Category = "TamagOri | State Setup")
	EOriStates OriCurrentState = EOriStates::Young;
//--- State default Setup End ---//

//--- State management and events functions start ---//
	UFUNCTION()
	void ChangeState(EOriStates OriState);

	void YoungState();
	void AdultState();
	void HungryState();
	void ThirstState();
	void PoopyState();
	void DeadState();

	void SetImage(UTexture2D* OriTexture);
//--- State management and events functions start ---//
};

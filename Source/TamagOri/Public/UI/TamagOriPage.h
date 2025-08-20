#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TamagOriPage.generated.h"

class UImage;
class UTextBlock;
class UButtonWidget;
class UProgressBarWidget;

UENUM (BlueprintType)
enum class EOriStates : uint8
{
	Hungry UMETA(DisplayName = "Hungry"),
	Thirsty UMETA(DisplayName = "Thirsty"),
	Poopy UMETA(DisplayName = "Poopy"),
	Young UMETA(DisplayName = "Young"),
	Adult UMETA(Displayname = "Adult"),
	Dead UMETA(DisplayName = "Dead")
};

UCLASS()
class TAMAGORI_API UTamagOriPage : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativePreConstruct() override;
	

private:
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
	TObjectPtr<UTextBlock> OriStateText = nullptr;

	UPROPERTY(BlueprintReadWrite, meta=(BindWidget, AllowPrivateAccess = true), Category = "TamagOri | Personalization")
	TObjectPtr<UImage> OriImage = nullptr;

//--- Personalization ---//

	
//--- State Images Setup start ---//
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = true), Category = "TamagOri | State Setup")
	TObjectPtr<UTexture2D> HungryTexture = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = true), Category = "TamagOri | State Setup")
	TObjectPtr<UTexture2D> ThirstTexture = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = true), Category = "TamagOri | State Setup")
	TObjectPtr<UTexture2D> PoopTexture = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = true), Category = "TamagOri | State Setup")
	TObjectPtr<UTexture2D> YoungTexture = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = true), Category = "TamagOri | State Setup")
	TObjectPtr<UTexture2D> AdultTexture = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = true), Category = "TamagOri | State Setup")
	TObjectPtr<UTexture2D> DeadTexture = nullptr;
//--- State Images Setup end ---//
	
//--- State Setup Start ---//
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = true), Category = "TamagOri | State Setup")
	EOriStates OriCurrentState = EOriStates::Young;
//--- State Setup End ---//
	
};

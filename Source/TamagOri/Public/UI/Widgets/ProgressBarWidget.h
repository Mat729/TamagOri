#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ProgressBarWidget.generated.h"

enum class EOriStates : uint8;
class UButtonWidget;
class UProgressBar;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnStateChanged, EOriStates, OriState);

UCLASS()
class TAMAGORI_API UProgressBarWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativePreConstruct() override;
	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

private:
//--- ProgressBar Personalization Start ---//
	UPROPERTY(BlueprintReadWrite, EditInstanceOnly, meta = (BindWidget, AllowPrivateAccess = true))
	TObjectPtr<UProgressBar> ProgressBar = nullptr;

	UPROPERTY(BlueprintReadWrite, EditInstanceOnly, meta = (BindWidget, AllowPrivateAccess = true))
	FLinearColor BarColor = FLinearColor::White;

	UPROPERTY(BlueprintReadWrite, EditInstanceOnly, meta = (BindWidget, AllowPrivateAccess = true))
	float DecreseBarRate = 5.f;

	UPROPERTY(BlueprintReadWrite, EditInstanceOnly, meta = (BindWidget, AllowPrivateAccess = true))
	float ValueToAddOnButtonClick = 20.f;
	
	float CurrentBarPercent = 0.f;

	float PercentRoundedToFloat = 0.f;
	float NormalizedBarPercent = 0.f;
	
	UPROPERTY(VisibleInstanceOnly, meta = (AllowPrivateAccess = true))
	float BarMaxPercent = 100.f;
//--- ProgressBar Personalization End ---//

//--- ProgressBar utility functions Start ---//
	UFUNCTION()
	void IncreaseBarPercent();
//--- ProgressBar utility functions End ---//
	
//--- ProgressBar State Trigger functions Start ---//
	void DecreaseBarWithTime(float InDeltaTime);
	void NormalizeAndRoundPercent(float InCurrentBarPercent);
	void OriGrowth(float InDeltaTime);
//--- ProgressBar State Trigger functions End ---//

//--- State trigger Utility Start ---//
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
	EOriStates OriStateToTrigger;

	float TimePassed = 0;
	
	bool bHasTriggeredChange = false;

	bool bIsOriGrwon = false;

	bool bCanTick = true;
//--- State trigger Utility End ---//

//--- Button for binding Delegate ---//
	UPROPERTY(BlueprintReadWrite, EditInstanceOnly, meta = (AllowPrivateAccess = true))
	TObjectPtr<UButtonWidget> ButtonWidget;

public:
	UPROPERTY()
	FOnStateChanged OnStateChangedDelegate;

	void StopTicking(); 
};








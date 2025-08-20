#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ProgressBarWidget.generated.h"

class UButtonWidget;
class UProgressBar;

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
	float DecreseBarRate = 3.f;

	UPROPERTY(BlueprintReadWrite, EditInstanceOnly, meta = (BindWidget, AllowPrivateAccess = true))
	float ValueToAddOnButtonClick = 20.f;
	
	float CurrentBarPercent = 0.f;
	
	float BarMaxPercent = 100.f;
//--- ProgressBar Personalization End ---//

//--- ProgressBar utility functions Start ---//
	UFUNCTION()
	void IncreaseBarPercent();
//--- ProgressBar utility functions End ---//
	
//--- ProgressBar State Trigger functions Start ---//
	void DecreaseBarWithTime(float InDeltaTime);

	void NormalizeBarPercent(float InCurrentBarPercent);
//--- ProgressBar State Trigger functions End ---//


//--- Button for binding Delegate ---//
	UPROPERTY()
	TObjectPtr<UButtonWidget> ButtonWidget;
};





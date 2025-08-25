#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "OriDeathWidget.generated.h"

class UButtonWidget;

UCLASS()
class TAMAGORI_API UOriDeathWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

private:
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, meta = (BindWidget, AllowPrivateAccess = true))
	TObjectPtr<UButtonWidget> RetryButton = nullptr;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, meta = (BindWidget, AllowPrivateAccess = true))
	TObjectPtr<UButtonWidget> QuitButton = nullptr;

	UFUNCTION()
	void OnClickRetry();
	UFUNCTION()
	void OnClickQuit();
};

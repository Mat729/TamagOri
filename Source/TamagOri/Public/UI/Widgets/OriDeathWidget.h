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
//--- widgets binding start ---//
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, meta = (BindWidget, AllowPrivateAccess = true))
	TObjectPtr<UButtonWidget> RetryButton = nullptr;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, meta = (BindWidget, AllowPrivateAccess = true))
	TObjectPtr<UButtonWidget> QuitButton = nullptr;
//--- widgets binding end ---//

//--- Buttons logic functions start ---//
	UFUNCTION()
	void OnClickRetry();
	UFUNCTION()
	void OnClickQuit();
//--- Buttons logic functions end ---//
};

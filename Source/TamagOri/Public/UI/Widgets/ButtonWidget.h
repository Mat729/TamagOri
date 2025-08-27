#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ButtonWidget.generated.h"

class UTextBlock;
class UButton;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnButtonClicked);

UCLASS()
class TAMAGORI_API UButtonWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativePreConstruct() override;
	virtual void NativeConstruct() override;
	
private:
	
//--- Button bindings Start ---//
	UPROPERTY(BlueprintReadWrite, EditInstanceOnly, meta = (BindWidget, AllowPrivateAccess = true))
	TObjectPtr<UButton> Button = nullptr;

	UPROPERTY(BlueprintReadWrite, EditInstanceOnly, meta = (BindWidget, AllowPrivateAccess = true))
	TObjectPtr<UTextBlock> ButtonText = nullptr;
//--- Button bindings End ---//

//--- Button Personalization Start ---//
	UPROPERTY(BlueprintReadWrite, EditInstanceOnly, meta = (BindWidget, AllowPrivateAccess = true))
	FText InternalText;

	UPROPERTY(BlueprintReadWrite, EditInstanceOnly, meta = (AllowPrivateAccess = true))
	FLinearColor ButtonColor;
//--- Button Personalization End ---//

//--- Button Delegate broadcast function ---//
	UFUNCTION(BlueprintCallable)
	void OnClick();
	
public:
	FOnButtonClicked OnButtonClickedDelegate;
};

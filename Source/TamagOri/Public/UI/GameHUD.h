#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "GameHUD.generated.h"

class UTamagOriPage;

UCLASS()
class TAMAGORI_API AGameHUD : public AHUD
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
	TObjectPtr<UTamagOriPage> TamagOriPage = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
	TSubclassOf<UTamagOriPage> TamagOriPageClass = nullptr;

	UFUNCTION()
	void CreateWidgetAndAddToViewport();
};

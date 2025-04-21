#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EquipmentItemWidget.generated.h"


UCLASS()
class SPRITELAND_API UEquipmentItemWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void UpdateInfo(struct FEquipmentItemInfo* Info);

private:
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* AttackText;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* DefenceText;
};

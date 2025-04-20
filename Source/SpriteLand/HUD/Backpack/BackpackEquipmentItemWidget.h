#pragma once

#include "CoreMinimal.h"
#include "BackpackItemWidget.h"
#include "BackpackEquipmentItemWidget.generated.h"


UCLASS()
class SPRITELAND_API UBackpackEquipmentItemWidget : public UBackpackItemWidget
{
	GENERATED_BODY()
	
protected:
	virtual void OnUseButtonClicked();

	UPROPERTY(EditDefaultsOnly)
	UDataTable* EquipmentDataTable;
};

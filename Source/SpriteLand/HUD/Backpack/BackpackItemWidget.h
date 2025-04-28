#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BackpackItemWidget.generated.h"


UCLASS()
class SPRITELAND_API UBackpackItemWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeOnInitialized() override;

	class UBackpackWidget* BackpackWidget;

	void UpdateViewInfo(struct FConsumableItemInfo* InInfo, const int32 InCount);

	void UpdateViewInfo(struct FEquipmentItemInfo* InInfo, const int32 InCount);

protected:
	struct FItemInfoBase* Info;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class UEquipmentItemWidget> EquipmentItemWidgetClass;

	UFUNCTION(BlueprintCallable)
	virtual void OnUseButtonClicked();

	UPROPERTY(EditAnywhere)
	bool bIsInBackpack = true;

	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	bool bIsFilled = true;

private:
	UPROPERTY(meta = (BindWidget))
	class UImage* ItemImage;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* ItemAmountText;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* ItemNameText;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* ItemDescText;

	UPROPERTY(meta = (BindWidget))
	class UVerticalBox* ExtraInfoBox;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* FirstButtonText;
};

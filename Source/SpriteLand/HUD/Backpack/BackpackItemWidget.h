#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BackpackItemWidget.generated.h"

struct FItemInfoBase;

UCLASS()
class SPRITELAND_API UBackpackItemWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

	void UpdateViewInfo(FItemInfoBase* Info,const int32 InCount);


protected:
	FItemInfoBase* Info;

	UFUNCTION(BlueprintCallable)
	virtual void OnUseButtonClicked();

private:
	UPROPERTY(meta=(BindWidget))
	class UImage* ItemImage;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* ItemAmountText;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* ItemNameText;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* ItemDescText;
};

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SpriteLand/Systems/Feature/BackpackSystem/ItemInfo.h"
#include "BackpackWidget.generated.h"

UCLASS()
class SPRITELAND_API UBackpackWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeOnInitialized() override;
	virtual void NativeConstruct() override;

protected:
	void InitializeItemInfoCache();

	UFUNCTION(BlueprintCallable)
	void UpdateBackpackView();

	FItemInfoBase* FindItemInfoInTables(EItemName ItemName);

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UWrapBox* ItemWrapBox;

private:
	UPROPERTY()
	class ASpriteLandPlayerController* PlayerController;

	UPROPERTY()
	class UBackpackComponent* BackpackComponent;

	TMap<EItemName, FItemInfoBase*> ItemInfoCache;

	UPROPERTY(EditDefaultsOnly, Category = "DataTable")
	UDataTable* EquipmentDataTable;

	UPROPERTY(EditDefaultsOnly, Category = "DataTable")
	UDataTable* UsableDataTable;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class UBackpackItemWidget> ItemWidgetClass;
};

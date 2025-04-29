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
	void RefreshBackpackView_Equip();

	UFUNCTION(BlueprintCallable)
	void RefreshBackpackView_Consumable();

	//UFUNCTION(BlueprintCallable)
	//void RefreshBackpackView_Miscellaneous();

	//FItemInfoBase* FindItemInfoInTables(EItemName ItemName);

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UWrapBox* EquipItemWrapBox;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UWrapBox* ConsumableItemWrapBox;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UWrapBox* MiscellaneousItemWrapBox;

private:
	UPROPERTY()
	class ASpriteLandPlayerController* PlayerController;

	UPROPERTY()
	class UBackpackComponent* BackpackComponent;

	UPROPERTY()
	class AHeroCharacterBase* HeroCharacter;

	TMap<EConsumableItemName, FConsumableItemInfo*> ConsumableItemInfoCache;

	TMap<EEquipmentItemName, FEquipmentItemInfo*> EquipmentItemInfoCache;

	UPROPERTY(EditDefaultsOnly, Category = "DataTable")
	UDataTable* WeaponDataTable;

	UPROPERTY(EditDefaultsOnly, Category = "DataTable")
	UDataTable* ConsumableDataTable;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class UBackpackItemWidget> ItemWidgetClass;

public:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UBackpackItemWidget* WeaponSlot;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* AttackValueText;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* DefenseValueText;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* HealthText;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* AttackSpeedText;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* ManaText;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* MoveSpeedText;

public:
	void UpdateCharacterInfo();
};

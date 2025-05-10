#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ItemInfo.h"
#include "BackpackComponent.generated.h"

USTRUCT(BlueprintType)
struct FEquipmentItemStack
{
	GENERATED_BODY();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EEquipmentItemName ItemName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 Count;
};

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SPRITELAND_API UBackpackComponent : public UActorComponent
{
	GENERATED_BODY()

	friend class ASpriteLandPlayerController;

public:
	UBackpackComponent();

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	class ASpriteLandPlayerController* PlayerController;

private:
	UPROPERTY(EditDefaultsOnly, Category = "DataTable")
	UDataTable* WeaponDataTable;

	UPROPERTY(EditDefaultsOnly, Category = "DataTable")
	UDataTable* ConsumableDataTable;

	TMap<EEquipmentItemName, FEquipmentItemInfo*> EquipmentItemInfoCache;

	TMap<EConsumableItemName, FConsumableItemInfo*> ConsumableItemInfoCache;

	UPROPERTY(EditAnyWhere)
	TMap<EConsumableItemName, int32> ConsumbleItems;

	UPROPERTY(EditAnyWhere)
	TMap<EEquipmentItemName, FEquipmentItemStack> EquipmentItems;

	void InitializeItemInfoCache();

public:
	bool UseItem(const EEquipmentItemName ItemName, const int32 Count = 1);

	bool UseItem(const EConsumableItemName ItemName, const int32 Count = 1);

	bool UnEquip(const EEquipmentItemName ItemName);

	//bool AddItem(const EItemType ItemType, const EItemName ItemName, const int32 Count = 1);
	//bool RemoveItem(const EItemType ItemType, const EItemName ItemName, const int32 Count = 1);

	//UPROPERTY(EditAnyWhere)
	//TMap<EItemName, int32> QuestItems;

	//UPROPERTY(EditAnyWhere)
	//TMap<EItemName, int32> MiscellaneousItems;

public:
	FORCEINLINE TMap<EConsumableItemName, FConsumableItemInfo*>& GetConsumableItemInfoCache() {
		return ConsumableItemInfoCache;
	}
	FORCEINLINE TMap<EEquipmentItemName, FEquipmentItemInfo*>& GetEquipmentItemInfoCache() {
		return EquipmentItemInfoCache;
	}

	FORCEINLINE TMap<EConsumableItemName, int32>& GetComsumbleItems() { return ConsumbleItems; }
	FORCEINLINE TMap<EEquipmentItemName, FEquipmentItemStack>& GetEquipmentItems() { return EquipmentItems; }
	//FORCEINLINE TMap<EItemName, int32>& GetQuestItems() { return QuestItems; }
	//FORCEINLINE TMap<EItemName, int32>& GetMiscellaneousItems() { return MiscellaneousItems; }

};

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

public:
	UBackpackComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	virtual void BeginPlay() override;

protected:
	//bool AddItem(const EItemType ItemType, const EItemName ItemName, const int32 Count = 1);
	//bool RemoveItem(const EItemType ItemType, const EItemName ItemName, const int32 Count = 1);
	//bool UseItem(const EItemName ItemName, const int32 Count = 1);
private:

	UPROPERTY(EditAnyWhere)
	TMap<EConsumableItemName, int32> ConsumbleItems;

	UPROPERTY(EditAnyWhere)
	TMap<EEquipmentItemName, FEquipmentItemStack> EquipmentItems;

	//UPROPERTY(EditAnyWhere)
	//TMap<EItemName, int32> QuestItems;

	//UPROPERTY(EditAnyWhere)
	//TMap<EItemName, int32> MiscellaneousItems;

public:
	FORCEINLINE TMap<EConsumableItemName, int32>& GetComsumbleItems() { return ConsumbleItems; }
	FORCEINLINE TMap<EEquipmentItemName, FEquipmentItemStack>& GetEquipmentItems() { return EquipmentItems; }
	//FORCEINLINE TMap<EItemName, int32>& GetQuestItems() { return QuestItems; }
	//FORCEINLINE TMap<EItemName, int32>& GetMiscellaneousItems() { return MiscellaneousItems; }

};

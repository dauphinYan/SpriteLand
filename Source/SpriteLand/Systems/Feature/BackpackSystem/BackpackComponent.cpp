#include "BackpackComponent.h"
#include "SpriteLand/Interface/CharacterActionInterface.h"
#include "SpriteLand/Interface/BuffInterface.h"
#include "SpriteLand/Systems/Core/GamePlay/SpriteLandPlayerController.h"
#include "../EquipmentSystem/EquipmentBase.h"
#include "Kismet/GameplayStatics.h"

UBackpackComponent::UBackpackComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UBackpackComponent::BeginPlay()
{
	Super::BeginPlay();

	InitializeItemInfoCache();
}

void UBackpackComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

template <typename ItemNameType, typename ItemType>
auto LoadTable = [&](UDataTable* Table, TMap<ItemNameType, ItemType*>& Cache)
	{
		if (!Table) return;

		for (auto& RowName : Table->GetRowNames())
		{
			if (ItemType* Row = Table->FindRow<ItemType>(RowName, TEXT("ItemInfoCache")))
			{
				Cache.Add(Row->ItemName, Row);
			}
		}
	};

void UBackpackComponent::InitializeItemInfoCache()
{
	if (WeaponDataTable)
	{
		LoadTable<EEquipmentItemName, FEquipmentItemInfo>(WeaponDataTable, EquipmentItemInfoCache);
	}
	if (ConsumableDataTable)
	{
		LoadTable<EConsumableItemName, FConsumableItemInfo>(ConsumableDataTable, ConsumableItemInfoCache);
	}

}

bool UBackpackComponent::UseItem(const EEquipmentItemName ItemName, const int32 Count)
{
	FEquipmentItemInfo* EquipmentInfo = EquipmentItemInfoCache[ItemName];
	if (!EquipmentInfo) return false;
	UClass* LoadedClass = EquipmentInfo->EquipmentClass.LoadSynchronous();
	if (LoadedClass)
	{
		ICharacterActionInterface* Interface = Cast<ICharacterActionInterface>(PlayerController->GetPawn());
		if (Interface)
		{
			Interface->Equip(GetWorld()->SpawnActor<AEquipmentBase>(LoadedClass));
			if (EquipSound)
				UGameplayStatics::PlaySound2D(GetWorld(), EquipSound);
			return true;
		}
	}

	return false;
}

bool UBackpackComponent::UseItem(const EConsumableItemName ItemName, const int32 Count)
{
	IBuffInterface* Interface = Cast<IBuffInterface>(PlayerController->GetPawn());
	if (Interface && ConsumableItemInfoCache.Find(ItemName))
	{
		Interface->RestoreHealth(ConsumableItemInfoCache[ItemName]->EffectValue);
		ConsumableItems[ItemName]--;
		return true;
	}

	return false;
}

bool UBackpackComponent::UnEquip(const EEquipmentItemName ItemName)
{
	ICharacterActionInterface* Interface = Cast<ICharacterActionInterface>(PlayerController->GetPawn());
	if (Interface && EquipmentItemInfoCache[ItemName])
	{
		Interface->UnEquip(EquipmentItemInfoCache[ItemName]->EquipmentType);
		if (UnEquipSound)
			UGameplayStatics::PlaySound2D(GetWorld(), UnEquipSound);
		return true;
	}

	return false;
}

//bool UBackpackComponent::AddItem(const EItemType ItemType, const EItemName ItemName, const int32 Count)
//{
//	if (ItemType == EItemType::Unknown || ItemName == EItemName::Unknown || Count <= 0)
//		return false;
//
//	switch (ItemType)
//	{
//	case EItemType::Consumable:
//	{
//		int32& ExistingCount = ConsumbleItems.FindOrAdd(ItemName);
//		ExistingCount += Count;
//		return true;
//	}
//	case EItemType::Equipment:
//	{
//		FEquipmentItemStack& Equipment = EquipmentItems.FindOrAdd(ItemName);
//		Equipment.ItemName = ItemName;
//		Equipment.Count += Count;
//		return true;
//	}
//	case EItemType::Quest:
//	{
//		int32& ExistingCount = QuestItems.FindOrAdd(ItemName);
//		ExistingCount += Count;
//		return true;
//	}
//	case EItemType::Miscellaneous:
//	{
//		int32& ExistingCount = MiscellaneousItems.FindOrAdd(ItemName);
//		ExistingCount += Count;
//		return true;
//	}
//	default:
//		return false;
//	}
//}
//
//
//bool UBackpackComponent::RemoveItem(const EItemType ItemType, const EItemName ItemName, const int32 Count)
//{
//	if (ItemType == EItemType::Unknown || ItemName == EItemName::Unknown || Count <= 0)
//		return false;
//
//	switch (ItemType)
//	{
//	case EItemType::Consumable:
//	{
//		int32* FoundCount = ConsumbleItems.Find(ItemName);
//		if (FoundCount && *FoundCount >= Count)
//		{
//			*FoundCount -= Count;
//			if (*FoundCount <= 0)
//				ConsumbleItems.Remove(ItemName);
//			return true;
//		}
//		break;
//	}
//	case EItemType::Equipment:
//	{
//		FEquipmentItemStack* FoundStack = EquipmentItems.Find(ItemName);
//		if (FoundStack && FoundStack->Count >= Count)
//		{
//			FoundStack->Count -= Count;
//			if (FoundStack->Count <= 0)
//				EquipmentItems.Remove(ItemName);
//			return true;
//		}
//		break;
//	}
//	case EItemType::Quest:
//	{
//		int32* FoundCount = QuestItems.Find(ItemName);
//		if (FoundCount && *FoundCount >= Count)
//		{
//			*FoundCount -= Count;
//			if (*FoundCount <= 0)
//				QuestItems.Remove(ItemName);
//			return true;
//		}
//		break;
//	}
//	case EItemType::Miscellaneous:
//	{
//		int32* FoundCount = MiscellaneousItems.Find(ItemName);
//		if (FoundCount && *FoundCount >= Count)
//		{
//			*FoundCount -= Count;
//			if (*FoundCount <= 0)
//				MiscellaneousItems.Remove(ItemName);
//			return true;
//		}
//		break;
//	}
//	default:
//		break;
//	}
//
//	return false;
//}

//bool UBackpackComponent::UseItem(const EItemName ItemName, const int32 Count)
//{
//
//	return false;
//}

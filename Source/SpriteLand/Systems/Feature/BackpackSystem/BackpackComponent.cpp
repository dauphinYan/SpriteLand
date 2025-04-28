#include "BackpackComponent.h"


UBackpackComponent::UBackpackComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UBackpackComponent::BeginPlay()
{
	Super::BeginPlay();

}

void UBackpackComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

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

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

bool UBackpackComponent::AddItem(const EItemName ItemName, const int32 Count)
{
	if (Count <= 0) return false;

	if (!HasSpaceForItem(ItemName, Count))
	{
		return false;
	}

	if (Items.Find(ItemName) != nullptr)
	{
		Items[ItemName] += Count;
	}
	else
	{
		Items.Add(ItemName);
		++Items[ItemName];
	}

	CurrentCapacity += Count;

	return true;
}

bool UBackpackComponent::RemoveItem(const EItemName ItemName, const int32 Count)
{
	if (Count <= 0) return false;

	int32* ExistingCount = Items.Find(ItemName);
	if (ExistingCount == nullptr || *ExistingCount < Count)
	{
		return false;
	}

	*ExistingCount -= Count;
	CurrentCapacity -= Count;

	if (*ExistingCount == 0)
	{
		Items.Remove(ItemName);
	}

	return true;
}

bool UBackpackComponent::HasSpaceForItem(const EItemName ItemName, const int32 Count)
{
	if (CurrentCapacity + Count > Capacity)
	{
		return false;
	}

	return true;
}

void UBackpackComponent::SetCapacity(const int32 NewCapacity)
{
	if (NewCapacity < 0) return;

	Capacity = NewCapacity;

	if (CurrentCapacity > Capacity)
	{
		// Some logics to solve items which is out of capacity.
	}

}
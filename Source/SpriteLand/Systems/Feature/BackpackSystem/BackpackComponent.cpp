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
	if (ItemName == EItemName::Unknown || Count <= 0)
	{
		return false;
	}

	// 查找已有的物品栈
	for (FItemStack& Stack : ItemArray)
	{
		if (Stack.ItemName == ItemName)
		{
			Stack.Count += Count;
			return true;
		}
	}

	// 没有找到则新建一条记录
	FItemStack NewStack;
	NewStack.ItemName = ItemName;
	NewStack.Count = Count;
	ItemArray.Add(NewStack);

	return true;
}

bool UBackpackComponent::RemoveItem(const EItemName ItemName, const int32 Count)
{
	if (ItemName == EItemName::Unknown || Count <= 0)
	{
		return false;
	}

	// 查找已有的物品栈
	for (int32 Index = 0; Index < ItemArray.Num(); ++Index)
	{
		FItemStack& Stack = ItemArray[Index];
		if (Stack.ItemName == ItemName)
		{
			if (Stack.Count < Count)
			{
				// 数量不足
				return false;
			}

			Stack.Count -= Count;
			if (Stack.Count == 0)
			{
				// 如果数量归零，则移除该条目
				ItemArray.RemoveAt(Index);
			}
			return true;
		}
	}


	return false;
}
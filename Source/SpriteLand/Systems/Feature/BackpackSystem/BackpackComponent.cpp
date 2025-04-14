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

	// �������е���Ʒջ
	for (FItemStack& Stack : ItemArray)
	{
		if (Stack.ItemName == ItemName)
		{
			Stack.Count += Count;
			return true;
		}
	}

	// û���ҵ����½�һ����¼
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

	// �������е���Ʒջ
	for (int32 Index = 0; Index < ItemArray.Num(); ++Index)
	{
		FItemStack& Stack = ItemArray[Index];
		if (Stack.ItemName == ItemName)
		{
			if (Stack.Count < Count)
			{
				// ��������
				return false;
			}

			Stack.Count -= Count;
			if (Stack.Count == 0)
			{
				// ����������㣬���Ƴ�����Ŀ
				ItemArray.RemoveAt(Index);
			}
			return true;
		}
	}


	return false;
}
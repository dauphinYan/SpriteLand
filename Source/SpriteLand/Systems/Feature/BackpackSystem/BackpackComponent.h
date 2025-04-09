#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ItemInfo.h"
#include "BackpackComponent.generated.h"


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
	bool AddItem(const EItemName ItemName, const int32 Count = 1);
	bool RemoveItem(const EItemName ItemName, const int32 Count = 1);
	bool HasSpaceForItem(const EItemName ItemName, const int32 Count = 1);
	void SetCapacity(const int32 NewCapacity);
private:
	int32 Capacity = 20;
	int32 CurrentCapacity = 0;

	UPROPERTY(EditAnyWhere)
	TMap<EItemName, int32> Items;

public:
	FORCEINLINE const int32 GetCapacity() const { return Capacity; }
	FORCEINLINE const TMap<EItemName, int32>& GetItems() const { return Items; }
};

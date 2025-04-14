#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ItemInfo.h"
#include "BackpackComponent.generated.h"

USTRUCT(BlueprintType)
struct FItemStack
{
	GENERATED_BODY();

	// 物品类型
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EItemName ItemName;

	// 当前数量
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
	bool AddItem(const EItemName ItemName, const int32 Count = 1);
	bool RemoveItem(const EItemName ItemName, const int32 Count = 1);
private:
	UPROPERTY(EditAnyWhere)
	TArray<FItemStack> ItemArray;

public:
	FORCEINLINE const TArray<FItemStack>& GetItems() const { return ItemArray; }
};

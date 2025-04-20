#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpriteLand/Systems/Feature/BackpackSystem/ItemInfo.h"
#include "EquipmentBase.generated.h"

UCLASS()
class SPRITELAND_API AEquipmentBase : public AActor
{
	GENERATED_BODY()

public:
	AEquipmentBase();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

protected:
	UPROPERTY(EditDefaultsOnly)
	class UStaticMeshComponent* EquipmentMesh;

protected:
	UPROPERTY(EditDefaultsOnly)
	UDataTable* EquipmentDatatable;

	UPROPERTY(EditDefaultsOnly)
	EItemName EquipmentName;

	EEquipmentType EquipmentType;

	float AttackValue = 0.f;

public:
	FORCEINLINE EEquipmentType GetEquipmentType() { return EquipmentType; }
};

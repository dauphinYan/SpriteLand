#pragma once

#include "CoreMinimal.h"
#include "SpriteLand/Systems/Feature/EquipmentSystem/EquipmentBase.h"
#include "WeaponBase.generated.h"

UCLASS()
class SPRITELAND_API AWeaponBase : public AEquipmentBase
{
	GENERATED_BODY()
	
public:
	AWeaponBase();

protected:
	UPROPERTY(EditDefaultsOnly)
	class UBoxComponent* CollisionBox;
};

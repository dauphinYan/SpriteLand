#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EquipmentComponent.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SPRITELAND_API UEquipmentComponent : public UActorComponent
{
	GENERATED_BODY()

	friend class AHeroCharacterBase;

public:
	UEquipmentComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


protected:
	virtual void BeginPlay() override;

	class AHeroCharacterBase* HeroCharacter;

private:
	class AWeaponBase* Weapon;



public:
	void EquipWeapon(AWeaponBase* InWeapon);

	void WeaponAttack();
};

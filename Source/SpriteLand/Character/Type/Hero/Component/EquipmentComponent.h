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

private:
	class AWeaponBase* Weapon;

	class AHeroCharacterBase* HeroCharacter;

public:
	void EquipWeapon(AWeaponBase* InWeapon);

	void UnEquipWeapon();

	UFUNCTION(BlueprintCallable)
	void WeaponAttackStart();

	UFUNCTION(BlueprintCallable)
	void WeaponAttackEnd();

public:
	FORCEINLINE AWeaponBase* GetWeapon() { return Weapon; }
};

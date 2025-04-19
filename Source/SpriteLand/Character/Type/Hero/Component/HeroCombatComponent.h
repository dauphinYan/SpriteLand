#pragma once

#include "CoreMinimal.h"
#include "SpriteLand/Character/Common/CombatComponent.h"
#include "HeroCombatComponent.generated.h"


UCLASS()
class SPRITELAND_API UHeroCombatComponent : public UCombatComponent
{
	GENERATED_BODY()

	friend class AHeroCharacterBase;

protected:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	virtual void Attack() override;

private:
	class AHeroCharacterBase* HeroCharacter;

	class UEquipmentComponent* EquipmentComponent;

	int32 CurrentAttackCombo = 0;

	float ComboTimer = 0.f;

	UPROPERTY(EditDefaultsOnly)
	float MaxComboTime = 0.5f;

	UPROPERTY(EditAnywhere)
	class UAnimMontage* AttackMontage;

	void PlayAttackMontage();
};

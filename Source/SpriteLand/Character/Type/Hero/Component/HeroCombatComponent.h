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

protected:
	class AHeroCharacterBase* HeroCharacter;

	class UEquipmentComponent* EquipmentComponent;

	UAnimInstance* AnimInstance;

protected: // Attack
	UPROPERTY(BlueprintReadWrite)
	bool bIsAttacking = false;

	int32 CurrentAttackCombo = 0;

	float ComboTimer = 0.f;

	UFUNCTION(BlueprintCallable)
	virtual void Attack() override;

	void PlayAttackMontage();

protected: // Hit
	UPROPERTY(EditDefaultsOnly)
	UAnimMontage* HitMontage;

	void PlayHitMontage(int32 Level);

	UFUNCTION()
	void OnHitMontageEnded(UAnimMontage* Montage, bool bInterrupted);

};

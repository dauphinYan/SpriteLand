#include "HeroCombatComponent.h"
#include "EquipmentComponent.h"
#include "SpriteLand/Character/Type/Hero/HeroCharacterBase.h"
#include "Animation/AnimInstance.h"

void UHeroCombatComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (ComboTimer > 0.f)
	{
		ComboTimer -= DeltaTime;
		if (ComboTimer <= 0.f)
		{
			CurrentAttackCombo = 0;
		}
	}
}

void UHeroCombatComponent::Attack()
{
	if (!HeroCharacter) return;

	if (CurrentAttackCombo == 0)
	{
		CurrentAttackCombo = 1;
		PlayAttackMontage();
	}
	else if (ComboTimer > 0.f)
	{
		CurrentAttackCombo++;
		if (CurrentAttackCombo > 3) CurrentAttackCombo = 1;
		PlayAttackMontage();
	}
}

void UHeroCombatComponent::PlayAttackMontage()
{
	HeroCharacter->PlayAnimMontage(AttackMontage, 1.f, FName(*FString::Printf(TEXT("Attack_%d"), CurrentAttackCombo)));

	ComboTimer = MaxComboTime;
}

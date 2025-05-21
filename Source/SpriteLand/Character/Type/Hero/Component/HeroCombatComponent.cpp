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
	if (!HeroCharacter || bIsAttacking || EquipmentComponent) return;

	if (CurrentAttackCombo == 0)
	{
		CurrentAttackCombo = 1;
		PlayAttackMontage();
	}
	else if (ComboTimer > 0.f)
	{
		CurrentAttackCombo++;
		if (CurrentAttackCombo > MaxAttackCombo) CurrentAttackCombo = 1;
		PlayAttackMontage();
	}
}

void UHeroCombatComponent::PlayAttackMontage()
{
	AnimInstance = AnimInstance == nullptr ? HeroCharacter->GetMesh()->GetAnimInstance() : AnimInstance;
	if (AnimInstance && AttackMontage)
	{
		AnimInstance->Montage_Play(AttackMontage, 1.f);

		FName SectionName = FName(*FString::Printf(TEXT("Attack_%d"), CurrentAttackCombo));
		AnimInstance->Montage_JumpToSection(SectionName, AttackMontage);
		float MontageLengh = AttackMontage->GetSectionLength(CurrentAttackCombo);
		ComboTimer = MontageLengh + 0.8f;

		bIsAttacking = true;
	}
}

void UHeroCombatComponent::PlayHitMontage(int32 Level)
{
	AnimInstance = AnimInstance == nullptr ? HeroCharacter->GetMesh()->GetAnimInstance() : AnimInstance;
	if (AnimInstance && HitMontage)
	{
		AnimInstance->Montage_Play(HitMontage, 1.f);
		FName SectionName = FName(*FString::Printf(TEXT("Hit_%d"), Level));
		AnimInstance->Montage_JumpToSection(SectionName, HitMontage);

		FOnMontageEnded OnMontageEnded;
		OnMontageEnded.BindUObject(this, &UHeroCombatComponent::OnHitMontageEnded);

		AnimInstance->Montage_SetEndDelegate(OnMontageEnded, HitMontage);
		HeroCharacter->SetCanMove(false);
	}
}

void UHeroCombatComponent::OnHitMontageEnded(UAnimMontage* Montage, bool bInterrupted)
{
	HeroCharacter->SetCanMove(true);
}

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
	if (!HeroCharacter || bIsAttacking) return;

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
	UAnimInstance* AnimInstance = HeroCharacter->GetMesh()->GetAnimInstance();
	if (AnimInstance)
	{
		//FOnMontageEnded EndDelegate;
		//EndDelegate.BindUObject(this, &UHeroCombatComponent::OnAttackMontageEnded);
		AnimInstance->Montage_Play(AttackMontage, 1.f);
		//AnimInstance->Montage_SetEndDelegate(EndDelegate, AttackMontage);

		FName SectionName = FName(*FString::Printf(TEXT("Attack_%d"), CurrentAttackCombo));
		AnimInstance->Montage_JumpToSection(SectionName, AttackMontage);

		float MontageLengh = AttackMontage->GetSectionLength(CurrentAttackCombo);
		ComboTimer = MontageLengh + 0.8f;

		bIsAttacking = true;
	}
}

//void UHeroCombatComponent::PlayAttackMontage()
//{
//	UAnimInstance* AnimInstance = HeroCharacter->GetMesh()->GetAnimInstance();
//	if (AnimInstance)
//	{
//		FOnMontageEnded EndDelegate;
//		EndDelegate.BindUObject(this, &UHeroCombatComponent::OnAttackMontageEnded);
//		AnimInstance->Montage_Play(AttackMontage, 1.f);
//		AnimInstance->Montage_SetEndDelegate(EndDelegate, AttackMontage);
//
//		FName SectionName = FName(*FString::Printf(TEXT("Attack_%d"), CurrentAttackCombo));
//		AnimInstance->Montage_JumpToSection(SectionName, AttackMontage);
//		float MontageLengh = AttackMontage->GetSectionLength(CurrentAttackCombo);
//
//		ComboTimer = MontageLengh + 0.8f;
//		bIsAttacking = true;
//	}
//}

//void UHeroCombatComponent::OnAttackMontageEnded(UAnimMontage* Montage, bool bInterrupted)
//{
//	if (Montage == AttackMontage)
//	{
//		bIsAttacking = false;
//
//		if (ComboTimer <= 0.f)
//		{
//			CurrentAttackCombo = 0;
//		}
//	}
//}
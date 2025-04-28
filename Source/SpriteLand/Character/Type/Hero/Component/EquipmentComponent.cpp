#include "EquipmentComponent.h"
#include "SpriteLand/Systems/Feature/EquipmentSystem/Weapon/WeaponBase.h"
#include "SpriteLand/Character/Type/Hero/HeroCharacterBase.h"
#include "Engine/SkeletalMeshSocket.h"

UEquipmentComponent::UEquipmentComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UEquipmentComponent::BeginPlay()
{
	Super::BeginPlay();

}

void UEquipmentComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UEquipmentComponent::EquipWeapon(AWeaponBase* InWeapon)
{
	if (InWeapon == nullptr) return;

	if (HeroCharacter == nullptr)
		HeroCharacter = Cast<AHeroCharacterBase>(GetOwner());

	if (HeroCharacter)
	{
		UnEquipWeapon();

		Weapon = InWeapon;

		const USkeletalMeshComponent* Mesh = HeroCharacter->GetMesh();
		if (!Mesh)
		{
			UE_LOG(LogTemp, Error, TEXT("Not found HeroCharacter mesh!"));
			return;
		}
		Weapon->AttachToComponent(HeroCharacter->GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, FName("hand_r_weapon"));
		Weapon->SetOwner(HeroCharacter);

	}
}

void UEquipmentComponent::UnEquipWeapon()
{
	if (Weapon)
	{
		Weapon->Destroy();
	}

	Weapon = nullptr;
}

void UEquipmentComponent::WeaponAttackStart()
{
	if (Weapon)
	{
		Weapon->AttackStart();
	}

}

void UEquipmentComponent::WeaponAttackEnd()
{
	if (Weapon)
	{
		Weapon->AttackEnd();
	}
}

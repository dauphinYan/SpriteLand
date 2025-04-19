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
		if (Weapon)
		{
			Weapon->Destroy();
		}

		Weapon = InWeapon;
		const USkeletalMeshSocket* HandSocket = HeroCharacter->GetMesh()->GetSocketByName(FName("hand_r_weapon"));
		if (!HandSocket)
		{
			UE_LOG(LogTemp, Error, TEXT("Socket 'hand_r_weapon' not found on mesh!"));
			return;
		}
		HandSocket->AttachActor(Weapon, HeroCharacter->GetMesh());

	}
}

void UEquipmentComponent::WeaponAttack()
{

}
#include "MageCombatComponent.h"
#include "../EquipmentComponent.h"
#include "SpriteLand/Systems/Feature/EquipmentSystem/Weapon/WeaponBase.h"

void UMageCombatComponent::Attack()
{
	if (EquipmentComponent)
	{
		AWeaponBase* Weapon = EquipmentComponent->GetWeapon();
		if (Weapon)
		{
			Weapon->AttackStart();
		}
	}
}

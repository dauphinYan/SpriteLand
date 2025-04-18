#include "WeaponBase.h"
#include "Components/BoxComponent.h"

AWeaponBase::AWeaponBase()
{
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Collsion Box"));
	CollisionBox->SetupAttachment(EquipmentMesh);
}
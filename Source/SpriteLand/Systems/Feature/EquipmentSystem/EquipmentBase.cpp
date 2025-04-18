#include "EquipmentBase.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"

AEquipmentBase::AEquipmentBase()
{

	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Weapon Mesh"));
	WeaponMesh->SetupAttachment(RootComponent);

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Collsion Box"));
	CollisionBox->SetupAttachment(WeaponMesh);
}

void AEquipmentBase::BeginPlay()
{
	Super::BeginPlay();

	auto LoadTable = [&](UDataTable* Table)
		{
			if (!Table) return;

			static const FString ContextString(TEXT("Looking for weapon data."));

			for (auto& RowName : Table->GetRowNames())
			{
				if (FEquipmentItemInfo* Row = Table->FindRow<FEquipmentItemInfo>(RowName, ContextString))
				{
					if (Row->ItemName == WeaponName)
					{
						AttackValue = Row->AttackValue;
						break;
					}
				}
			}
		};

	LoadTable(EquipmentDatatable);
}

void AEquipmentBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


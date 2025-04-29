#include "EquipmentBase.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"

AEquipmentBase::AEquipmentBase()
{

	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	EquipmentMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Equipment Mesh"));
	EquipmentMesh->SetupAttachment(RootComponent);
	EquipmentMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AEquipmentBase::BeginPlay()
{
	Super::BeginPlay();

	if (EquipmentDataTable)
	{
		for (auto& RowName : EquipmentDataTable->GetRowNames())
		{
			if (FEquipmentItemInfo* Row = EquipmentDataTable->FindRow<FEquipmentItemInfo>(RowName, TEXT("Looking for equipment data.")))
			{
				if (Row->ItemName == EquipmentName)
				{
					AttackValue = Row->AttackValue;
					EquipmentType = Row->EquipmentType;
					break;
				}
			}
		}
	}
}

void AEquipmentBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


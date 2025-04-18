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

	auto LoadTable = [&](UDataTable* Table)
		{
			if (!Table) return;

			static const FString ContextString(TEXT("Looking for equipment data."));

			for (auto& RowName : Table->GetRowNames())
			{
				if (FEquipmentItemInfo* Row = Table->FindRow<FEquipmentItemInfo>(RowName, ContextString))
				{
					if (Row->ItemName == EquipmentName)
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


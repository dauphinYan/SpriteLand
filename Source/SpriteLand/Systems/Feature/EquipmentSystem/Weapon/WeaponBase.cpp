#include "WeaponBase.h"
#include "Components/BoxComponent.h"
#include "SpriteLand/Character/Type/Enemy/EnemyCharacterBase.h"
#include "Kismet/GameplayStatics.h"

AWeaponBase::AWeaponBase()
{
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Collsion Box"));
	CollisionBox->SetupAttachment(EquipmentMesh);
	CollisionBox->SetCollisionObjectType(ECC_WorldDynamic);
	CollisionBox->SetCollisionResponseToAllChannels(ECR_Ignore);
	CollisionBox->SetCollisionResponseToChannel(ECC_Enemy, ECR_Overlap);
}

void AWeaponBase::BeginPlay()
{
	Super::BeginPlay();

	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &AWeaponBase::OnBoxOverlap);
}

void AWeaponBase::AttackStart()
{
	HitTargets.Empty();
	CollisionBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
}

void AWeaponBase::AttackEnd()
{
	CollisionBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}



void AWeaponBase::OnBoxOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && !HitTargets.Contains(OtherActor))
	{
		AEnemyCharacterBase* Enemy = Cast<AEnemyCharacterBase>(OtherActor);
		if (Enemy)
		{
			UGameplayStatics::ApplyDamage(
				Enemy,
				10.f,
				Owner->GetInstigatorController(),
				this,
				UDamageType::StaticClass()
			);
			HitTargets.Add(OtherActor);
		}

	}
}

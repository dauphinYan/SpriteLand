#include "LongSword.h"
#include "Components/BoxComponent.h"
#include "SpriteLand/Character/Type/Enemy/EnemyCharacterBase.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"

ALongSword::ALongSword()
{
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Collsion Box"));
	CollisionBox->SetupAttachment(EquipmentMesh);
	CollisionBox->SetCollisionObjectType(ECC_WorldDynamic);
	CollisionBox->SetCollisionResponseToAllChannels(ECR_Ignore);
	CollisionBox->SetCollisionResponseToChannel(ECC_Enemy, ECR_Overlap);
	CollisionBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void ALongSword::BeginPlay()
{
	Super::BeginPlay();

	CollisionBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &ALongSword::OnBoxOverlap);
}

void ALongSword::AttackStart()
{
	HitTargets.Empty();
	CollisionBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
}

void ALongSword::AttackEnd()
{
	CollisionBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void ALongSword::OnBoxOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!OtherActor || OtherActor == GetOwner()) return;

	float CurrentTime = GetWorld()->GetTimeSeconds();
	float* LastHitTime = LastHitTimeMap.Find(OtherActor);

	if (!LastHitTime || (CurrentTime - *LastHitTime >= MinHitInterval))
	{
		AEnemyCharacterBase* Enemy = Cast<AEnemyCharacterBase>(OtherActor);
		if (Enemy)
		{
			UGameplayStatics::ApplyDamage(
				Enemy,
				AttackValue,
				Owner->GetInstigatorController(),
				this,
				UDamageType::StaticClass()
			);
			LastHitTimeMap.Add(OtherActor, CurrentTime);
		}

		if (HitSound)
		{
			UGameplayStatics::PlaySoundAtLocation(
				GetWorld(),
				HitSound,
				OtherActor->GetActorLocation()
			);
		}
	}
}

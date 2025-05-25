#include "EnemyCharacterBase.h"
#include "Sound/SoundWave.h"
#include "Kismet/GameplayStatics.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"
#include "SpriteLand/Systems/Core/GamePlay/SpriteLandGameMode.h"
#include "TimerManager.h"
#include "Components/BoxComponent.h"
#include "Components/CapsuleComponent.h"

AEnemyCharacterBase::AEnemyCharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore);

	GetMesh()->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	GetMesh()->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision Box"));
	CollisionBox->SetupAttachment(RootComponent);
	CollisionBox->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	CollisionBox->SetCollisionResponseToChannel(ECC_WorldDynamic, ECollisionResponse::ECR_Overlap);
	CollisionBox->SetCollisionObjectType(ECC_Enemy);
}

void AEnemyCharacterBase::BeginPlay()
{
	Super::BeginPlay();

	OnTakeAnyDamage.AddDynamic(this, &AEnemyCharacterBase::ReceiveDamage);

	if (EnemyDatatable)
	{
		for (auto& RowName : EnemyDatatable->GetRowNames())
		{
			if (auto RowData = EnemyDatatable->FindRow<FEnemyInfo>(RowName, TEXT("Enemy Info")))
			{
				if (RowData->EnemyName == EnemyName)
				{
					MaxHealth = RowData->Health;
					CurHealth = RowData->Health;
					AttackValue = RowData->AttackValue;
					DefenseValue = RowData->DefenseValue;
					DisplayName = RowData->DisplayName;
					break;
				}
			}
		}
	}

	if (AGameModeBase* BaseGM = UGameplayStatics::GetGameMode(this))
	{
		if (ASpriteLandGameMode* GM = Cast<ASpriteLandGameMode>(BaseGM))
		{
			GM->RegisterEnemy(this);
		}
	}
}

void AEnemyCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEnemyCharacterBase::ReceiveDamage(AActor* DamageActor, float Damage, const UDamageType* DamageType, AController* InstigatorController, AActor* DamageCauser)
{
	if (CurHealth - Damage > 0.f) // Enemy still alive.
	{
		if (HurtSound)
		{
			UGameplayStatics::SpawnSoundAtLocation(
				GetWorld(),
				HurtSound,
				GetActorLocation()
			);
		}
		CurHealth -= Damage;
	}
	else
	{
		CurHealth = 0.f;
	}

	// Update BossHealthBar if is Boss.
	if (IsBoss)
	{
		float HealthPercent = CurHealth / MaxHealth;
		OnCharacterReceiveDamage.Broadcast(DisplayName, HealthPercent);
	}

	int32 IntDamage = FMath::RoundToInt(Damage);
	if (IntDamage <= 0)
	{
		return;
	}

	TArray<int32> Digits;
	while (IntDamage > 0)
	{
		Digits.Insert(IntDamage % 10, 0);
		IntDamage /= 10;
	}

	if (!DamageFloatNiagara)
	{
		return;
	}

	const float OffsetX = 20.0f;
	for (int32 i = 0; i < Digits.Num(); ++i)
	{
		UNiagaraComponent* DigitEffect = UNiagaraFunctionLibrary::SpawnSystemAtLocation(
			GetWorld(),
			DamageFloatNiagara,
			GetActorLocation() + FVector(OffsetX * i, 0.f, 100.f),
			FRotator::ZeroRotator,
			FVector(1.f)
		);

		if (DigitEffect)
		{
			DigitEffect->SetVariableInt(FName("DigitCount"), Digits[i]);
		}
	}

	if (CurHealth == 0.f)
	{
		OnCharacterDeath.Broadcast(this);

		PlayDeathMontage();

		GetMesh()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		CollisionBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		GetCapsuleComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Ignore);

		GetWorldTimerManager().SetTimer(
			DeathTimer,
			this,
			&AEnemyCharacterBase::OnDeathMontageEnded,
			3.f
		);
	}
}

void AEnemyCharacterBase::PlayDeathMontage()
{
	if (DeathMontage)
	{
		UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
		if (AnimInstance)
		{
			AnimInstance->Montage_Play(DeathMontage);
		}
	}
}

void AEnemyCharacterBase::OnDeathMontageEnded()
{
	if (AGameModeBase* BaseGM = UGameplayStatics::GetGameMode(this))
	{
		if (ASpriteLandGameMode* GM = Cast<ASpriteLandGameMode>(BaseGM))
		{
			GM->UnregisterEnemy(this);
		}
	}

	Destroy();
}


//FText GetEnemyNameAsLocalizedText(const EEnemyName EnemyName)
//{
//	switch (EnemyName)
//	{
//	case EEnemyName::AnonymousThief:
//		return NSLOCTEXT("EnemyName", "AnonymousThief", "无名小怪");
//	default:
//		break;
//	}
//}
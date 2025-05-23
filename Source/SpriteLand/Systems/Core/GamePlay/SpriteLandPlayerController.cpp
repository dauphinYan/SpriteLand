#include "SpriteLandPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "SpriteLand/Systems/Feature/BackpackSystem/BackpackComponent.h"
#include "SpriteLand/HUD/SpriteLandHUD.h"
#include "SpriteLand/HUD/Backpack/BackpackWidget.h"
#include "SpriteLand/HUD/Main/MainWidget.h"
#include "SpriteLand/Character/Type/Enemy/EnemyCharacterBase.h"
#include "SpriteLand/Interface/CharacterActionInterface.h"
#include "SpriteLand/Interface/SkillInterface.h"
#include "Kismet/GameplayStatics.h"

ASpriteLandPlayerController::ASpriteLandPlayerController()
{
	BackpackComponent = CreateDefaultSubobject<UBackpackComponent>(TEXT("Backpack Component"));
}

void ASpriteLandPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (APlayerController* PC = Cast<APlayerController>(this))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}

	if (SpriteLandHUD == nullptr)
	{
		SpriteLandHUD = Cast<ASpriteLandHUD>(GetHUD());
	}

	BackpackComponent->PlayerController = this;
}

void ASpriteLandPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	if (CurrentLockingTarget)
	{
		FVector WorldLocation = CurrentLockingTarget->GetMesh()->GetSocketLocation(FName("head_socket"));
		FVector2D ScreenPosition;

		DrawDebugSphere(
			GetWorld(),
			WorldLocation,
			50.f,
			16,
			FColor::Red,
			false,
			2.0f
		);

		if (ProjectWorldLocationToScreen(WorldLocation, ScreenPosition, true))
		{
			SpriteLandHUD->LockingTarget(ScreenPosition);
		}
	}
}

void ASpriteLandPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInput->BindAction(JumpAction, ETriggerEvent::Started, this, &ASpriteLandPlayerController::OnJumpButtonPressed);
		EnhancedInput->BindAction(JumpAction, ETriggerEvent::Completed, this, &ASpriteLandPlayerController::OnJumpButtonReleased);
		EnhancedInput->BindAction(DodgeAction, ETriggerEvent::Started, this, &ASpriteLandPlayerController::OnDodgeButtonPressed);
		EnhancedInput->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ASpriteLandPlayerController::OnMoveButtonTriggered);
		EnhancedInput->BindAction(RunAction, ETriggerEvent::Started, this, &ASpriteLandPlayerController::OnRunButtonPressed);
		//EnhancedInput->BindAction(RunAction, ETriggerEvent::Completed, this, &ASpriteLandPlayerController::OnRunButtonReleased);
		EnhancedInput->BindAction(LookAction, ETriggerEvent::Triggered, this, &ASpriteLandPlayerController::OnLookButtonTriggered);
		EnhancedInput->BindAction(AttackAction, ETriggerEvent::Started, this, &ASpriteLandPlayerController::OnAttackButtonPressed);
		EnhancedInput->BindAction(BackpackAction, ETriggerEvent::Started, this, &ASpriteLandPlayerController::OnBackpackButtonPressed);
		EnhancedInput->BindAction(SkillAction_1, ETriggerEvent::Started, this, &ASpriteLandPlayerController::OnSkillButtonPressed_1);
		EnhancedInput->BindAction(SkillAction_2, ETriggerEvent::Started, this, &ASpriteLandPlayerController::OnSkillButtonPressed_2);
		EnhancedInput->BindAction(LockAction, ETriggerEvent::Started, this, &ASpriteLandPlayerController::OnLockButtonPressed);
	}
}

void ASpriteLandPlayerController::OnJumpButtonPressed()
{
	if (GetPawn() && GetPawn()->Implements<UCharacterActionInterface>())
	{
		ICharacterActionInterface* Interface = Cast<ICharacterActionInterface>(GetPawn());
		if (Interface)
		{
			Interface->JumpBegin();
		}
	}
}

void ASpriteLandPlayerController::OnJumpButtonReleased()
{

}

void ASpriteLandPlayerController::OnMoveButtonTriggered(const FInputActionValue& Value)
{
	if (GetPawn() && GetPawn()->Implements<UCharacterActionInterface>())
	{
		ICharacterActionInterface* Interface = Cast<ICharacterActionInterface>(GetPawn());
		if (Interface)
		{
			Interface->Move(Value);
		}
	}
}

void ASpriteLandPlayerController::OnRunButtonPressed()
{
	if (GetPawn() && GetPawn()->Implements<UCharacterActionInterface>())
	{
		ICharacterActionInterface* Interface = Cast<ICharacterActionInterface>(GetPawn());
		if (Interface)
		{
			Interface->StartRunning();
		}
	}
}

void ASpriteLandPlayerController::OnRunButtonReleased()
{
	if (GetPawn() && GetPawn()->Implements<UCharacterActionInterface>())
	{
		ICharacterActionInterface* Interface = Cast<ICharacterActionInterface>(GetPawn());
		if (Interface)
		{
			Interface->StopRunning();
		}
	}
}

void ASpriteLandPlayerController::OnLookButtonTriggered(const FInputActionValue& Value)
{
	if (GetPawn() && GetPawn()->Implements<UCharacterActionInterface>())
	{
		ICharacterActionInterface* Interface = Cast<ICharacterActionInterface>(GetPawn());
		if (Interface)
		{
			Interface->Look(Value);
		}
	}
}


void ASpriteLandPlayerController::OnDodgeButtonPressed()
{

}

void ASpriteLandPlayerController::OnAttackButtonPressed()
{
	if (GetPawn() && GetPawn()->Implements<UCharacterActionInterface>())
	{
		ICharacterActionInterface* Interface = Cast<ICharacterActionInterface>(GetPawn());
		if (Interface)
		{
			Interface->Attack();
		}
	}
}

void ASpriteLandPlayerController::OnBackpackButtonPressed()
{
	if (SpriteLandHUD == nullptr)
	{
		SpriteLandHUD = Cast<ASpriteLandHUD>(GetHUD());
	}

	if (SpriteLandHUD)
	{
		if (SpriteLandHUD->SetBackpackView())
		{
			SetShowMouseCursor(true);
			FInputModeGameAndUI InputMode;
			InputMode.SetWidgetToFocus(SpriteLandHUD->GetBackpackWidget()->TakeWidget());
			InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
			SetInputMode(InputMode);
		}
		else
		{
			SetShowMouseCursor(false);
			FInputModeGameOnly InputMode;
			SetInputMode(InputMode);
		}
	}

}

void ASpriteLandPlayerController::OnSkillButtonPressed_1()
{
	if (GetPawn() && GetPawn()->Implements<USkillInterface>())
	{
		ISkillInterface* Interface = Cast<ISkillInterface>(GetPawn());
		if (Interface)
		{
			Interface->UseSkillByButton(0);
		}
	}
}

void ASpriteLandPlayerController::OnSkillButtonPressed_2()
{
	if (GetPawn() && GetPawn()->Implements<USkillInterface>())
	{
		ISkillInterface* Interface = Cast<ISkillInterface>(GetPawn());
		if (Interface)
		{
			Interface->UseSkillByButton(1);
		}
	}
}

void ASpriteLandPlayerController::OnLockButtonPressed()
{
	if (CurrentLockingTarget)
	{
		CurrentLockingTarget = nullptr;
	}
	else
	{
		CurrentLockingTarget = FindBestLockTarget(1000.f, 45.f);
	}
}

TArray<AActor*> ASpriteLandPlayerController::FindEnemiesInRange(float Radius)
{
	TArray<AActor*> OutActors;
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
	ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_Pawn));

	TArray<AActor*> IgnoreActors;
	IgnoreActors.Add(GetPawn());

	UKismetSystemLibrary::SphereOverlapActors(
		this,
		GetPawn()->GetActorLocation(),
		Radius,
		ObjectTypes,
		AEnemyCharacterBase::StaticClass(),
		IgnoreActors,
		OutActors
	);

	return OutActors;
}

AEnemyCharacterBase* ASpriteLandPlayerController::FindBestLockTarget(float Radius, float MaxAngleDegree)
{
	APawn* MyPawn = GetPawn();
	if (!MyPawn) return nullptr;

	FVector MyLocation = MyPawn->GetActorLocation();
	FVector Forward = MyPawn->GetActorForwardVector();

	AEnemyCharacterBase* BestTarget = nullptr;
	float BestScore = FLT_MAX;

	for (AActor* Actor : FindEnemiesInRange(Radius))
	{
		AEnemyCharacterBase* Enemy = Cast<AEnemyCharacterBase>(Actor);
		if (!Enemy || !Enemy->IsAlive()) continue;

		FVector ToEnemy = Enemy->GetActorLocation() - MyLocation;
		ToEnemy.Z = 0.f;
		float Distance = ToEnemy.Size();

		ToEnemy.Normalize();
		float Dot = FVector::DotProduct(Forward, ToEnemy);
		float Angle = FMath::Acos(Dot) * 180.f / PI;

		if (Angle <= MaxAngleDegree)
		{
			if (Distance < BestScore)
			{
				BestScore = Distance;
				BestTarget = Enemy;
			}
		}
	}
	return BestTarget;
}


void ASpriteLandPlayerController::SetCurrentLockingTarget(AEnemyCharacterBase* InTarget)
{
	CurrentLockingTarget = InTarget;
}

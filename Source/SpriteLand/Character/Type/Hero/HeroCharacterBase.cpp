#include "HeroCharacterBase.h"
#include "Engine/LocalPlayer.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Controller.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "SpriteLand/Character/Type/Hero/Component/EquipmentComponent.h"
#include "SpriteLand/Character/Type/Hero/Component/HeroCombatComponent.h"
#include "SpriteLand/Character/Type/Hero/Component/HeroBuffComponent.h"
#include "SpriteLand/Systems/Feature/EquipmentSystem/Weapon/WeaponBase.h"
#include "SpriteLand/Systems/Core/GamePlay/SpriteLandPlayerController.h"
#include "SpriteLand/HUD/SpriteLandHUD.h"

AHeroCharacterBase::AHeroCharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f);

	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;
	GetCharacterMovement()->GravityScale = 1.5f;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f;
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	EquipmentComponent = CreateDefaultSubobject<UEquipmentComponent>(TEXT("EquipmentComponent"));
	CombatComponent = CreateDefaultSubobject<UHeroCombatComponent>(TEXT("CombatComponent"));
	BuffComponent = CreateDefaultSubobject<UHeroBuffComponent>(TEXT("BuffComponent"));
}

void AHeroCharacterBase::BeginPlay()
{
	Super::BeginPlay();

	OnTakeAnyDamage.AddDynamic(this, &AHeroCharacterBase::ReceiveDamage);

	PlayerController = PlayerController == nullptr ? Cast<ASpriteLandPlayerController>(Controller) : PlayerController;
	if (!PlayerController)
		return;
	PlayerController->GetSpriteLandHUD()->UpdateCharacterHealthBar(CurHealth, HealthTotal);

	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
}

void AHeroCharacterBase::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	if (EquipmentComponent)
	{
		EquipmentComponent->HeroCharacter = this;
	}
	if (CombatComponent)
	{
		CombatComponent->HeroCharacter = this;
		CombatComponent->EquipmentComponent = EquipmentComponent;
	}
	if (BuffComponent)
	{
		BuffComponent->HeroCharacter = this;
	}
}

void AHeroCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AHeroCharacterBase::Move(const FInputActionValue& Value)
{
	if (bCanMove == false)
		return;

	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		// get right vector
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement
		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void AHeroCharacterBase::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void AHeroCharacterBase::StartRunning()
{
	if (bIsRunning)
	{
		bIsRunning = false;
		GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
	}
	else
	{
		bIsRunning = true;
		GetCharacterMovement()->MaxWalkSpeed = RunSpeed;
	}
}

void AHeroCharacterBase::StopRunning()
{
	bIsRunning = false;
	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
}

void AHeroCharacterBase::Dodge()
{
	if (DodgeMontage != nullptr)
	{
		PlayAnimMontage(DodgeMontage);
	}
}

void AHeroCharacterBase::JumpBegin()
{
	Jump();
}

void AHeroCharacterBase::Attack()
{
	if (CombatComponent)
	{
		CombatComponent->Attack();
	}
}

void AHeroCharacterBase::Equip(AEquipmentBase* Equipment)
{
	switch (Equipment->GetEquipmentType())
	{
	default:
		break;
	case EEquipmentType::Weapon:
		if (EquipmentComponent)
		{
			EquipmentComponent->EquipWeapon(Cast<AWeaponBase>(Equipment));
		}

		break;
	}
}

void AHeroCharacterBase::UnEquip(EEquipmentType EquipmentType)
{
	switch (EquipmentType)
	{
	case EEquipmentType::Weapon:
		if (EquipmentComponent)
		{
			EquipmentComponent->UnEquipWeapon();
		}
		break;
	case EEquipmentType::Helmet:
		break;
	case EEquipmentType::Armor:
		break;
	case EEquipmentType::Boot:
		break;
	default:
		break;
	}
}

void AHeroCharacterBase::SetCanMove(bool InbCanMove)
{
	bCanMove = InbCanMove;
}

void AHeroCharacterBase::ReceiveDamage(AActor* DamageActor, float Damage, const UDamageType* DamageType, AController* InstigatorController, AActor* DamageCauser)
{
	if (CurHealth - Damage > 0.f)
	{
		CurHealth -= Damage;
		CombatComponent->PlayHitMontage(1);
	}
	else
	{
		CurHealth = 0.f;
	}

	PlayerController = PlayerController == nullptr ? Cast<ASpriteLandPlayerController>(Controller) : PlayerController;
	if (!PlayerController) return;
	PlayerController->GetSpriteLandHUD()->UpdateCharacterHealthBar(CurHealth, HealthTotal);
}

void AHeroCharacterBase::RestoreHealth(float InValue)
{
	if (BuffComponent)
	{
		BuffComponent->RestoreHealth(InValue);
		PlayerController = PlayerController == nullptr ? Cast<ASpriteLandPlayerController>(Controller) : PlayerController;
		if (!PlayerController) return;
		PlayerController->GetSpriteLandHUD()->UpdateCharacterHealthBar(CurHealth, HealthTotal);
	}
}

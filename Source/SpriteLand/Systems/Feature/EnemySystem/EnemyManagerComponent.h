#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EnemyManagerComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SPRITELAND_API UEnemyManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UEnemyManagerComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	void RegisterEnemy(class AEnemyCharacterBase* Enemy);

	void UnregisterEnemy(AEnemyCharacterBase* Enemy);

private:
	class ASpriteLandPlayerController* PlayerController;
};

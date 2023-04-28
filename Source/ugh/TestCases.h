#pragma once
#include "grub.h"
#include "soldier.h"
#include "tank.h"
#include "enemySpawn.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseTower.h"
#include <vector>
#include "TestCases.generated.h"
UCLASS() class UGH_API ATestCases : public AActor {
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATestCases();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FVector spawn{ 0.0, 50.0, 0.0 };
	FRotator allign{ 0.0 };
	FActorSpawnParameters base{};

	void addmoney();
	void losemoney();
	void towerSpawn();
	void grubSpawn();
	void soldierSpawn();
	void tankSpawn();

	
};

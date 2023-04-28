// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "grub.h"
#include "EnemyList.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseTower.generated.h"

UCLASS()
class UGH_API ABaseTower : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseTower();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
		USceneComponent* Root;
	UPROPERTY(EditDefaultsOnly)
		UStaticMeshComponent* TurretSprite;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		UStaticMeshComponent* TurretRange;

	void NotifyActorOnClicked(FKey ButtonPressed = EKeys::LeftMouseButton) override;

	void NotifyActorBeginOverlap(AActor* OtherActor) override;
	void NotifyActorEndOverlap(AActor* OtherActor) override;

	EnemyList targetList;
	Aenemy* target;

	unsigned int CD;
	unsigned int fireCD;

	void fire();
	void checkTargets();


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

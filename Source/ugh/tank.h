// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "enemy.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "tank.generated.h"

UCLASS()
class UGH_API Atank : public Aenemy
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Atank();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintImplementableEvent)
		void GameOver();
};

//almost identical to grub, see grub for commenting

//coding by Tyler Cox

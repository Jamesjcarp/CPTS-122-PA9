// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "enemy.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "grub.generated.h"

UCLASS()
class UGH_API Agrub : public Aenemy
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Agrub();

	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintImplementableEvent)
		void GameOver();

};

//grub class, stores it's data and updates it's position

//coded by Tyler Cox
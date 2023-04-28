// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "enemySpawn.h"
#include "path.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Blueprint/UserWidget.h"
#include "enemy.generated.h"
UCLASS()
class UGH_API Aenemy : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Aenemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//variables:
	// --------------------------------------------------------------------------
	//enemy current health
	int health;

	//units enemy travels per tick
	int speed;

	//disctance along the track the enmy has traveled, for tower targetting
	int alongTrack;

	//tracks the path variable, this tells the enemy what step of it's path it is on
	int index;

	//temp variable used when traveling along the track, resets when the path distance is hit. see the enemies themselves for more info
	int curDistance;

	//the value provided by the enemy on kill
	int money;

	//tracks current position of enemy
	FVector curLocation;

	//the instructions that the enemy follows
	path follow;

	//the damage the bug does to the player
	int attack;
	//----------------------------------------------------------------------------
	
	//returns the alongTrack value for towers to read
	int getTrackPosition();

	//makes the bug take the specified damage
	void takeDamage(int damage);

	//kills the bug and awards cash
	void die();
	
	/*UFUNCTION(BlueprintImplementableEvent)
	void GameOver();*/


};

//this is the base class for all enemies
//it contains just some values that apply to all enemies and one function

//coded by Tyler Cox
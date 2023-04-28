// Fill out your copyright notice in the Description page of Project Settings.


#include "soldier.h"

// Sets default values
Asoldier::Asoldier()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	health = 75;
	speed = 3;
	alongTrack = 0;
	index = 0;
	curDistance = 0;
	curLocation = GetActorLocation();
	money = 20;
	attack = 3;
}

// Called when the game starts or when spawned
void Asoldier::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void Asoldier::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (index < 11) {
		if (curDistance < follow.getDistance(index)) {
			curLocation = GetActorLocation();
			if (follow.getDirection(index) == 'N') {
				curLocation.X += speed;
			}
			else if (follow.getDirection(index) == 'E') {
				curLocation.Y += speed;
			}
			else if (follow.getDirection(index) == 'S') {
				curLocation.X -= speed;
			}
			else {
				curLocation.Y -= speed;
			}
			SetActorLocation(curLocation);
			alongTrack += speed;
			curDistance += speed;
		}
		else {
			index++;
			curDistance = 0;
		}
	}
	else {
		//deal damage to player
		GameOver();
		Destroy();
		
	}
}


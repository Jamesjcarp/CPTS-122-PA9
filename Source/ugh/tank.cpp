// Fill out your copyright notice in the Description page of Project Settings.


#include "tank.h"

// Sets default values
Atank::Atank()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	health = 300;
	speed = 1;
	alongTrack = 0;
	index = 0;
	curDistance = 0;
	curLocation = GetActorLocation();
	money = 50;
	attack = 10;
}

// Called when the game starts or when spawned
void Atank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void Atank::Tick(float DeltaTime)
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


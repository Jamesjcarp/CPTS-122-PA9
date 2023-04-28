// Fill out your copyright notice in the Description page of Project Settings.


#include "grub.h"

// Sets default values
Agrub::Agrub()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//initialize variables:
	//----------------------------------
	health = 50;
	speed = 2;
	alongTrack = 0;
	index = 0;
	curDistance = 0;
	curLocation = GetActorLocation();
	money = 10;
	attack = 1;
	//----------------------------------

}

// Called when the game starts or when spawned
void Agrub::BeginPlay()
{
	Super::BeginPlay();

	
}

// Called every frame
void Agrub::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	//checks that bug is not finished with path
	if (index < 11) {
		//loops till enough enough distance has been traveled, then increments index
		if (curDistance < follow.getDistance(index)) {
			//get's the current location so that it can be changed
			curLocation = GetActorLocation();
			//note: x and y coords flipped for somne reason. not happy about it :(
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
			//updates location
			SetActorLocation(curLocation);
			
			//updates distance trackers
			alongTrack += speed;
			curDistance += speed;
		}
		else {
			//go to next step and reset curDistance
			index++;
			curDistance = 0;
		}
	}
	else {
		//GEngine->AddOnScreenDebugMessage(-1, .5F, FColor::Yellow, TEXT("bye bye"));
		GameOver();
		Destroy();
		//destroys bug at end of track.
		//takes damage
		
	}
}



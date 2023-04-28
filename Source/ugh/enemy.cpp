// Fill out your copyright notice in the Description page of Project Settings.


#include "enemy.h"

//extranious functions included by unreal
//-------------------------------------------------------------------
// Sets default values
Aenemy::Aenemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}
// Called when the game starts or when spawned
void Aenemy::BeginPlay()
{
	Super::BeginPlay();
	
}
// Called every frame
void Aenemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
//--------------------------------------------------------------------

//returns the alongTrack value;
int Aenemy::getTrackPosition() {
	return alongTrack;
}

void Aenemy::takeDamage(int damage) {
	health -= damage;
	if (health <= 0) {
		die();
	}
}

void Aenemy::die() {
	//add cash to player
	AenemySpawn::coins += money;
	//if need to debug
	//GEngine->AddOnScreenDebugMessage(-1, .5F, FColor::Yellow, FString::Printf(TEXT("%d"), AenemySpawn::coins));
	Destroy();
}

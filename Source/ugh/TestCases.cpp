// Fill out your copyright notice in the Description page of Project Settings.


#include "TestCases.h"

// Sets default values
ATestCases::ATestCases()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATestCases::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATestCases::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

void ATestCases::addmoney() {
	AenemySpawn::coins += 1000;
}
void ATestCases::losemoney() {
	AenemySpawn::coins -= 1000;
}
void ATestCases::towerSpawn() {
	ABaseTower* t1 = GetWorld()->SpawnActor<ABaseTower>(ABaseTower::StaticClass(), spawn, allign, base);
}
void ATestCases::grubSpawn() {
	Agrub* g1 = GetWorld()->SpawnActor<Agrub>(Agrub::StaticClass(), spawn, allign, base);
}
void ATestCases::soldierSpawn() {
	Asoldier* s1 = GetWorld()->SpawnActor<Asoldier>(Asoldier::StaticClass(), spawn, allign, base);
}
void ATestCases::tankSpawn() {
	Atank* tk1 = GetWorld()->SpawnActor<Atank>(Atank::StaticClass(), spawn, allign, base);
}
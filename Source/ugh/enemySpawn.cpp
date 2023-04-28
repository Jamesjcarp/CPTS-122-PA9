// Fill out your copyright notice in the Description page of Project Settings.


#include "enemySpawn.h"

// Sets default values
AenemySpawn::AenemySpawn()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//initializing data:
	//--------------------------------
	file = FPaths::ProjectDir();
	file.Append(TEXT("round1.txt"));
	FFileHelper::LoadFileToStringArray(data, *file);
	waitFrames = 0;
	spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	pause = false;
	round = 1;
	//--------------------------------
	
}
int AenemySpawn::coins = 0;
// Called when the game starts or when spawned
void AenemySpawn::BeginPlay()
{
	Super::BeginPlay();
	coins = 100;
}

// Called every frame
void AenemySpawn::Tick(float DeltaTime)
{
	//main enemy spawning loop
	Super::Tick(DeltaTime);
	//first if will check that our data list is not emptry, avoiding a nullptr error.
	//also checks that the game is not paused to prevent running between rounds
	if (!data.IsEmpty() && !pause) {
		//the files have cooldown times listed between enemy spawns this makes sure you're off cooldown
		if (waitFrames <= 0) {
			//read a line
			line = data.Pop();
			//these three just choose which bug to spawn
			if (line == "G") {
				GetWorld()->SpawnActor<AActor>(grub, GetActorTransform(), spawnParams);
			}
			else if (line == "S") {
				GetWorld()->SpawnActor<AActor>(soldier, GetActorTransform(), spawnParams);
			}
			else if (line == "T") {
				GetWorld()->SpawnActor<AActor>(tank, GetActorTransform(), spawnParams);
			}
			//if the read string isn't one of those three, then it's a number specifying the amount of ticks to wait for before continuing
			else {
				waitFrames = FCString::Atoi(*line);
			}
		}
		//reduces wait frames
		else {
			waitFrames--;
		}
	}
	else {
		//the string is empty, move onto next round
		round++;
		pause = true;
		//buffer between rounds
		waitFrames = 800;
		changeRound();
		//waits till file is successfully opened to continue
		if (!data.IsEmpty()) {
			pause = false;
		}
	}
	
}

void AenemySpawn::changeRound() {
	//this is miserable but I couldn't get %d to work with me. just appends the correct file title to the directory for reading
	file = FPaths::ProjectDir();
	if (round == 2) {
		file.Append(TEXT("round2.txt"));
	}
	else if (round == 3) {
		file.Append(TEXT("round3.txt"));
	}
	else if (round == 4) {
		file.Append(TEXT("round4.txt"));
	}
	else if (round == 5) {
		file.Append(TEXT("round5.txt"));
	}
	else if (round == 6) {
		file.Append(TEXT("round6.txt"));
	}
	else if (round == 7) {
		file.Append(TEXT("round7.txt"));
	}
	else if (round == 8) {
		file.Append(TEXT("round8.txt"));
	}
	else if (round == 9) {
		file.Append(TEXT("round9.txt"));
	}
	else if (round == 10) {
		file.Append(TEXT("round10.txt"));
	}
	else if (round == 11) {
		file.Append(TEXT("round11.txt"));
	}
	else if (round == 12) {
		file.Append(TEXT("round12.txt"));
	}
	else if (round == 13) {
		file.Append(TEXT("round13.txt"));
	}
	else if (round == 14) {
		file.Append(TEXT("round14.txt"));
	}
	else if (round == 15) {
		file.Append(TEXT("round15.txt"));
	}
	else if (round == 16) {
		file.Append(TEXT("round16.txt"));
	}
	else if (round == 17) {
		file.Append(TEXT("round17.txt"));
	}
	else if (round == 18) {
		file.Append(TEXT("round18.txt"));
	}
	else if (round == 19) {
		file.Append(TEXT("round19.txt"));
	}
	else if (round == 20) {
		file.Append(TEXT("round20.txt"));
	}
	//reads the file
	FFileHelper::LoadFileToStringArray(data, *file);
}

int AenemySpawn::getCoins() {
	return coins;
}

void AenemySpawn::addTower() {
	coins -= 100;
}
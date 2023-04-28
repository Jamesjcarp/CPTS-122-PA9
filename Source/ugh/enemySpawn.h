// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "enemySpawn.generated.h"

UCLASS()
class UGH_API AenemySpawn : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AenemySpawn();

	//the slots for the objects to instantiate by the spawner
	UPROPERTY(EditAnywhere)
		TSubclassOf<AActor> grub;
	UPROPERTY(EditAnywhere)
		TSubclassOf<AActor> soldier;
	UPROPERTY(EditAnywhere)
		TSubclassOf<AActor> tank;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	static int coins;

	UFUNCTION(BlueprintCallable)
		int getCoins();
	UFUNCTION(BlueprintCallable)
		void addTower();
	

private:
	//variables:
	// ----------------------------------------------------------------
	//string that represents the current file being read
	FString file;

	//a single string of text with the entire file on it
	TArray<FString> data;

	//string of just one line of data
	FString line;

	//represents a cooldown between when the next enemy should be spawned
	int waitFrames;

	//unreal junk, ignore
	FActorSpawnParameters spawnParams;

	//represents the current round and opens the corresponding file
	int round;

	//denotes whether the tick loop should wait for a bit before contiuing operations. this is to prevent runoff round increases
	bool pause;
	//----------------------------------------------------------------

	//reads the next round file and pauses the tick loop while doing it
	void changeRound();
};

//controls the rounds and instantiates the correct enemies on queue

//coded by Tyler Cox

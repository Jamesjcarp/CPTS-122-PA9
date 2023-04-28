// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseTower.h"

// Sets default values
ABaseTower::ABaseTower()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	SetRootComponent(Root);

	TurretSprite = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TurretSprite"));
	TurretSprite->SetupAttachment(Root);

	TurretRange = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TurretRange"));
	TurretRange->SetupAttachment(Root);

	CD = 0;
	fireCD = 0;
}

// Called when the game starts or when spawned
void ABaseTower::BeginPlay()
{
	Super::BeginPlay();
	
	
}

// Called every frame
void ABaseTower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (CD == 0) {
		fire();
	}
	else {
		CD--;
	}
}

void ABaseTower::NotifyActorOnClicked(FKey ButtonPressed) {
	Super::NotifyActorOnClicked(ButtonPressed);

	if (TurretRange->GetVisibleFlag() == true) {
		TurretRange->SetVisibility(false);
	}
	else if (TurretRange->GetVisibleFlag() == false) {
		TurretRange->SetVisibility(true);
	}


}

void ABaseTower::NotifyActorBeginOverlap(AActor* OtherActor) {
	Super::NotifyActorBeginOverlap(OtherActor);
	Aenemy* bug = dynamic_cast<Aenemy*>(OtherActor);


	targetList.addList(bug);

}

void ABaseTower::NotifyActorEndOverlap(AActor* OtherActor) {
	Super::NotifyActorEndOverlap(OtherActor);
	Aenemy* bug = dynamic_cast<Aenemy*>(OtherActor);

	targetList.delist(bug);


}

void ABaseTower::fire() {

	if (fireCD == 0) {
		checkTargets();
		fireCD = 5;
	}
	else {
		fireCD--;
	}

}

void ABaseTower::checkTargets() {

	if (targetList.getHead() != NULL) {
		EnemyNode* pCur;
		pCur = targetList.getHead();
		target = targetList.getHead()->getBug();
		while (pCur != NULL) {
			if (pCur->getBug()->getTrackPosition() > target->getTrackPosition()) {
				target = pCur->getBug();
			}
			pCur = pCur->getNext();
		}
		target->takeDamage(50);
		CD = 45;
	}
}



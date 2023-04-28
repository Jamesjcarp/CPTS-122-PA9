// Fill out your copyright notice in the Description page of Project Settings.


#include "MouseController.h"

void AMouseController::BeginPlay() {
	Super::BeginPlay();
	SetInputMode(FInputModeGameAndUI());
}
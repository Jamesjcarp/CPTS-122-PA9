// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class UGH_API path
{
public:
	path();
	~path();

	int getDistance(int index);
	char getDirection(int index);

private:
	int distance[11];
	char direction[11];
};

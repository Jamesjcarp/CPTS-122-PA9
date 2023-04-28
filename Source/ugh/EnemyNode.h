// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "enemy.h"

/**
 * 
 */
class UGH_API EnemyNode
{
public:
	EnemyNode(Aenemy* newBug);
	~EnemyNode();

	void setBug(Aenemy* newBug);
	void setNext(EnemyNode* newNext);

	Aenemy* getBug();
	EnemyNode* getNext();
private:
	Aenemy* bug;
	EnemyNode* pNext;
};

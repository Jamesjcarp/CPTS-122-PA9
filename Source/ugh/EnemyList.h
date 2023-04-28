// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyNode.h"
/**
 * 
 */
class UGH_API EnemyList
{
public:
	EnemyList();
	~EnemyList();

	void setHead(EnemyNode* newHead);

	EnemyNode* getHead();

	void addList(Aenemy* newEnemy);

	void delist(Aenemy* curEnemy);


private:
	EnemyNode* pHead;
};

// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyNode.h"

EnemyNode::EnemyNode(Aenemy* newBug)
{
	this->bug = newBug;
}

EnemyNode::~EnemyNode()
{
	this->pNext = NULL;
	this->bug = NULL;
}

void EnemyNode::setBug(Aenemy* newBug) {
	this->bug = newBug;
}
void EnemyNode::setNext(EnemyNode* newNext) {
	this->pNext = newNext;
}

Aenemy* EnemyNode::getBug(){
	return this->bug;
}

EnemyNode* EnemyNode::getNext() {
	return this->pNext;
}
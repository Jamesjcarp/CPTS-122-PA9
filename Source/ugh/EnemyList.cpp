// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyList.h"

EnemyList::EnemyList()
{
}

EnemyList::~EnemyList()
{
}

void EnemyList::setHead(EnemyNode* newHead) {
	this->pHead = newHead;
}

EnemyNode* EnemyList::getHead() {
	return pHead;
}

void EnemyList::addList(Aenemy* newEnemy) {
	
	if (newEnemy->getTrackPosition() != NULL) {
		EnemyNode* newNode = new EnemyNode(newEnemy);

		
		newNode->setNext(pHead);
		pHead = newNode;
	}
}

void EnemyList::delist(Aenemy* curEnemy) {
	EnemyNode* pCur, * pPrev;

	pCur = this->pHead;
	pPrev = pCur;
	if (curEnemy->getTrackPosition() != NULL) {
		if (pHead->getBug() == curEnemy) {
			pHead = pCur->getNext();

		}
		else {

			while (pCur->getBug() != curEnemy) {
				pPrev = pCur;
				pCur = pCur->getNext();
			}

			pPrev->setNext(pCur->getNext());
		}
		delete pCur;
	}
	return;
}

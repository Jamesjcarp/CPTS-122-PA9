// Fill out your copyright notice in the Description page of Project Settings.


#include "path.h"

path::path()
{
	distance[0] = 200;
	direction[0] = 'E';

	distance[1] = 100;
	direction[1] = 'N';

	distance[2] = 200;
	direction[2] = 'E';

	distance[3] = 300;
	direction[3] = 'S';

	distance[4] = 200;
	direction[4] = 'E';

	distance[5] = 400;
	direction[5] = 'N';

	distance[6] = 300;
	direction[6] = 'E';

	distance[7] = 200;
	direction[7] = 'S';

	distance[8] = 100;
	direction[8] = 'W';

	distance[9] = 200;
	direction[9] = 'S';

	distance[10] = 400;
	direction[10] = 'E';
}

path::~path()
{
}

char path::getDirection(int index) {
	return direction[index];
}

int path::getDistance(int index) {
	return distance[index];
}


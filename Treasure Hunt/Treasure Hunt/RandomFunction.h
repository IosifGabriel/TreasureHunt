#pragma once
#include <random>
#include <time.h>
#ifndef RandFunction_H
#define RandFunction_H

inline int RandFunction()
{
	srand(time(NULL));
	int ANumber = rand();
	return ANumber;
}
#endif
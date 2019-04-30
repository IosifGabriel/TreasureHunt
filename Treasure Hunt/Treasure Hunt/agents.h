#pragma once
#include "map.h"

class map;

class agents
{
	char Name;

public:
	virtual void move(map &Map)=0;
	virtual int getterx()=0;
	virtual int gettery()=0;
	virtual bool ReturnFoundTreasure()=0;
	virtual char ReturnName() = 0;
	virtual bool GotBlocked()=0;
	agents();
	virtual ~agents();
};



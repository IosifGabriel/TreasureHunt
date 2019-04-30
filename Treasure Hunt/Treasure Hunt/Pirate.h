#pragma once
#include "agents.h"
class Pirate:public agents
{
	int x, y;
	bool FoundTreasure = false;
	bool Blocked = false;
	char Name = 'P';

public:
	Pirate();
	Pirate(int x, int y);
	char ReturnName();
	bool ReturnFoundTreasure();
	bool GotBlocked();
	void move(map &Map);
	int getterx();
	int gettery();

};


#pragma once
#include "agents.h"
class Warrior:public agents
{
	int x, y;
	bool FoundTreasure = false;
	bool Blocked = false;
	char Name = 'W';

public:
	Warrior();
	Warrior(int x, int y);
	char ReturnName();
	void move(map &Map);
	bool ReturnFoundTreasure();
	bool GotBlocked();
	int getterx();
	int gettery();

};


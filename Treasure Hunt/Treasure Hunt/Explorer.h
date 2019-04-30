#pragma once
#include "agents.h"
#include "map.h"
class Explorer:public agents
{
	int x, y;
	bool FoundTreasure = false;
	bool Blocked = false;
	char Name = 'E';
	

public:
	Explorer();
	Explorer(int x, int y);
	char ReturnName();
	void move(map &Map);
	bool ReturnFoundTreasure();
	bool GotBlocked();
	int getterx();
	int gettery();

};


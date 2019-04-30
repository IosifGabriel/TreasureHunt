#pragma once
#include "agents.h"
class Shaman:public agents
{
		int x, y;
		bool FoundTreasure = false;
		bool Blocked = false;
		char Name = 'S';

	public:
		Shaman();
		Shaman(int x, int y);
		char ReturnName();
		void move(map &Map);
		bool ReturnFoundTreasure();
		bool GotBlocked();
		int getterx();
		int gettery();

	
};

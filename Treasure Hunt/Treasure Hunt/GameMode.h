#pragma once
#include "map.h"
#include "agents.h"
#include <vector>

using namespace std;

class agents;
class map;

class GameMode
{
public:
	map TreasureHuntMap;
	int NumbOfRounds;
	int CountRounds;
	vector<agents*> Agents;
	int NumbOfTreasureFound;
	int NumbOfBlockedAgents;

	void AgentsInitialisation(vector<agents*> &Agents);
	GameMode();
	~GameMode();
	void SetRounds();
	int ReturnNumbOfRounds();
	map ReturnMap();
	void MoveAgents();
	void SetNumbOfTreasure(int x);
	void SetNumbOfBlockedAgents(int x);
	int ReturnNumbOfTreasure();
	int ReturnNumbOfBlockedAgents();

};


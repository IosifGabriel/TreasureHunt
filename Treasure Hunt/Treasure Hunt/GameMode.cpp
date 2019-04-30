#include "pch.h"
#include "GameMode.h"
#include <iostream>
#include <vector>
#include "RandomFunction.h"
#include "map.h"
#include "agents.h"
#include "Explorer.h"
#include "Shaman.h"
#include "Pirate.h"
#include "Warrior.h"
using namespace std;


void GameMode::AgentsInitialisation(vector<agents*> &Agents)
{

	Explorer *ExplorerAgent = new Explorer(0, 0);
	TreasureHuntMap.SetAgentsPositions(0, 0, 0, 0, ExplorerAgent);
	Warrior *WarriorAgent = new Warrior(TreasureHuntMap.GetRows() - 1, 0);
	TreasureHuntMap.SetAgentsPositions(TreasureHuntMap.GetRows()-1, 0,TreasureHuntMap.GetRows()-1 , 0, WarriorAgent);
	Shaman *ShamanAgent = new Shaman(0, TreasureHuntMap.GetCols() - 1);
	TreasureHuntMap.SetAgentsPositions(0, TreasureHuntMap.GetCols()-1, 0, TreasureHuntMap.GetCols()-1, ShamanAgent);
	Pirate *PirateAgent = new Pirate(TreasureHuntMap.GetRows() - 1, TreasureHuntMap.GetCols() - 1);
	TreasureHuntMap.SetAgentsPositions(TreasureHuntMap.GetRows()-1, TreasureHuntMap.GetRows()-1, TreasureHuntMap.GetCols()-1, TreasureHuntMap.GetCols()-1, PirateAgent);

	Agents.push_back(WarriorAgent);
	Agents.push_back(ShamanAgent);
	Agents.push_back(PirateAgent);
	Agents.push_back(ExplorerAgent);
}

void GameMode::SetNumbOfBlockedAgents(int x)
{
	NumbOfBlockedAgents = x;
}


void GameMode::MoveAgents()
{
	int counttreasure = 0;
	int countblocked = 0;
	for(int i=0;i<4;i++)
		if (Agents[i]->ReturnFoundTreasure() == false)
		{
			Agents[i]->move(TreasureHuntMap);
			if (Agents[i]->GotBlocked() == true)
				countblocked++;
			
		}
		else
		{
			counttreasure++;
		}
	SetNumbOfTreasure(counttreasure);
	SetNumbOfBlockedAgents(countblocked);

			

}

GameMode::GameMode()
{
	TreasureHuntMap.PrintMap();
	AgentsInitialisation(Agents);
	cout << "Dati numarul de runde"<<'\n'; 
	cin >> NumbOfRounds;
	CountRounds = 0;
	NumbOfTreasureFound = 0;
	
}

int GameMode::ReturnNumbOfBlockedAgents()
{
	return NumbOfBlockedAgents;
}

void GameMode::SetNumbOfTreasure(int x)
{
	NumbOfTreasureFound = x;
}

int GameMode::ReturnNumbOfTreasure()
{
	return NumbOfTreasureFound;
}

map GameMode::ReturnMap()	
{
	return TreasureHuntMap;
}

void GameMode::SetRounds()
{
	cin >> NumbOfRounds;
	CountRounds = 0;
}

GameMode::~GameMode()
{
}

int GameMode::ReturnNumbOfRounds()
{
	return NumbOfRounds;
}
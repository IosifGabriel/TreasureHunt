#include "pch.h"
#include <iostream>
#include "GameMode.h"
#include <windows.h>

using namespace std;

int main()
{
	GameMode Game;
	int i = 0;
	do
	{
		
		system("CLS");
		i++;
		Game.TreasureHuntMap.PrintMap();
		Game.MoveAgents();
		Sleep(1500);
		if (Game.ReturnNumbOfTreasure() == 3)
		{
			cout << " ALL TREASURES HAVE BEEN FOUND " << endl;
			break;
		}
		if (Game.NumbOfBlockedAgents >= 2)
		{
			cout << " More or two agents are blocked!" << endl;
			break;
		}

		if (i == Game.ReturnNumbOfRounds())
		{
			cout << endl;
			cout << "Do you want to play more rounds?" << endl;
			Game.SetRounds();
			i = 0;
		}


	} while (i <= Game.ReturnNumbOfRounds());

	cout << " GAME OVER ";


}

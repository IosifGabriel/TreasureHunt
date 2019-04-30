#include "pch.h"
#include "Shaman.h"
#include <iostream>
using namespace std;

Shaman::Shaman()
{
	x = 0;
	y = 0;

}

Shaman::Shaman(int xnew, int ynew)
{
	x = xnew;
	y = ynew;

}

int Shaman::getterx()
{
	return x;
}

int Shaman::gettery()
{
	return y;
}

bool Shaman::GotBlocked()
{
	return Blocked;
}

char Shaman::ReturnName()
{
	return Name;
}

void Shaman::move(map &Map)
{

	//going down-right
	if (x + 1 <= Map.GetRows() - 1 && y + 1 <= Map.GetCols() - 1)
		if (Map.Getxy(x + 1, y + 1) == '-' || Map.Getxy(x + 1, y + 1) == 'T')
		{

			if (Map.Getxy(x + 1, y + 1) == 'T')
			{
				FoundTreasure = true;
			}
			Map.SetAgentsPositions(x, y, x + 1, y + 1, this);
			if (FoundTreasure)
			{
				Map.Setxy(x + 1, y + 1);
				cout << Name << " has found a treasure!!!" << endl;
			}
			x++;
			y++;
			return;
		}


	//going down-left
	if (x + 1 <= Map.GetRows() - 1 && y - 1 > 0)
		if (Map.Getxy(x + 1, y - 1) == '-' || Map.Getxy(x + 1, y - 1) == 'T')
		{

			if (Map.Getxy(x + 1, y - 1) == 'T')
			{
				FoundTreasure = true;
			}
			Map.SetAgentsPositions(x, y, x + 1, y - 1, this);
			if (FoundTreasure)
			{
				Map.Setxy(x + 1, y - 1);
				cout << Name << " has found a treasure!!!" << endl;
			}
			x++;
			y--;
			return;
		}

	//going up-left
	if (x - 1 > 0  && y - 1 > 0)
		if (Map.Getxy(x - 1, y - 1) == '-' || Map.Getxy(x - 1, y - 1) == 'T')
		{

			if (Map.Getxy(x - 1, y - 1) == 'T')
			{
				FoundTreasure = true;
			}
			Map.SetAgentsPositions(x, y, x - 1, y - 1, this);
			if (FoundTreasure)
			{
				Map.Setxy(x - 1, y - 1);
				cout << Name << " has found a treasure!!!" << endl;
			}
			x--;
			y--;
			return;
		}
	//going up-right
	if (x - 1 > 0 && y + 1 <= Map.GetCols() - 1)
		if (Map.Getxy(x - 1, y + 1) == '-' || Map.Getxy(x - 1, y + 1) == 'T')
		{

			if (Map.Getxy(x - 1, y + 1) == 'T')
			{
				FoundTreasure = true;
			}
			Map.SetAgentsPositions(x, y, x - 1, y + 1, this);
			if (FoundTreasure)
			{
				Map.Setxy(x - 1, y + 1);
				cout << Name << " has found a treasure!!!" << endl;
			}
			x--;
			y++;
			return;
		}

	//Going up
	if (x - 1 > 0)
		if (Map.Getxy(x - 1, y) == '-' || Map.Getxy(x - 1, y) == 'T')
		{

			if (Map.Getxy(x - 1, y) == 'T')
			{
				FoundTreasure = true;
			}
			Map.SetAgentsPositions(x, y, x - 1, y, this);
			if (FoundTreasure)
			{
				Map.Setxy(x - 1, y);
				cout << Name << " has found a treasure!!!" << endl;
			}
			x--;
			return;
		}

	//going right
	if (y + 1 <= Map.GetCols() - 1)
		if (Map.Getxy(x, y + 1) == '-' || Map.Getxy(x, y + 1) == 'T')
		{

			if (Map.Getxy(x, y + 1) == 'T')
			{
				FoundTreasure = true;
			}
			Map.SetAgentsPositions(x, y, x, y + 1, this);
			if (FoundTreasure)
			{
				Map.Setxy(x, y + 1);
				cout << Name << " has found a treasure!!!" << endl;
			}
			y++;
			return;
		}
	// going left
	if (y - 1 > 0)
		if (Map.Getxy(x, y - 1) == '-' || Map.Getxy(x, y - 1) == 'T')
		{

			if (Map.Getxy(x, y - 1) == 'T')
			{
				FoundTreasure = true;
			}
			Map.SetAgentsPositions(x, y, x, y - 1, this);
			if (FoundTreasure)
			{
				Map.Setxy(x, y - 1);
				cout << Name << " has found a treasure!!!" << endl;
			}
			y--;
			return;
		}

	//going down
	if (x + 1 <= Map.GetRows() - 1)
		if (Map.Getxy(x + 1, y) == '-' || Map.Getxy(x + 1, y) == 'T')
		{

			if (Map.Getxy(x + 1, y) == 'T')
			{
				FoundTreasure = true;
			}
			Map.SetAgentsPositions(x, y, x + 1, y, this);
			if (FoundTreasure)
			{
				Map.Setxy(x + 1, y);
				cout << Name << " has found a treasure!!!" << endl;
			}
			x++;
			return;
		}

	Blocked = true;
	cout << Name << " HAS DIED " << endl;

}

bool Shaman::ReturnFoundTreasure()
{
	return FoundTreasure;
}

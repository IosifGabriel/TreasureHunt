#pragma once
#include "agents.h"

class agents;

class map
{
	char **Map;
	int rows, cols;

public:
	map();
	map(int rows, int cols);
	map(map const &other);
	~map();
	char Getxy(int x, int y);
	void Setxy(int x, int y);
	int GetRows();
	int GetCols();
	void Setter();  // for matrix dimension
	void SetRows(int row);
	void SetCols(int col); //end here
	void PrintMap();
	void TreasureGeneration();
	void SetAgentsPositions(int oldx, int oldy, int x,int y, agents *agent);

};


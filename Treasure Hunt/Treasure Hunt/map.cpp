#include "pch.h"
#include "map.h"
#include <iostream>
#include "RandomFunction.h"
using namespace std;

map::map()   // 15x15 constructor
{
	rows = 15;
	cols = 15;
	Map = new char*[rows];
	for (int i = 0; i < rows; i++)
		Map[i] = new char[cols];

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			Map[i][j] = '-';

	TreasureGeneration();
	
}

int map::GetRows()
{
	return rows;
}

int map::GetCols()
{
	return cols;
}

char map::Getxy(int x, int y)
{
	return Map[x][y];
}

void map::Setxy(int x, int y)
{
	Map[x][y] = '0';
}


void map::SetRows(int row)
{
	rows = row;
}

void map::SetCols(int col)
{
	cols = col;
}

void map::TreasureGeneration()
{

	for (int k = 0; k < 3; k++)
	{
		int i = RandFunction() % rows;
		int j = RandFunction() % cols;
		while (Map[i][j] == 'T' || ((i == 0 || i == rows - 1) && ( j == 0 || j == cols - 1)))
		{
			i = RandFunction() % rows;
			j = RandFunction() % cols;
		}
		Map[i][j] = 'T';
	}

}

map::map(int row, int col)   // constructor for given rows and cols 
{
	SetRows(row);
	SetCols(col);

	Map = new char*[rows];
	for (int i = 0; i < rows; i++)
		Map[i] = new char[cols];

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			Map[i][j] = '-';

	TreasureGeneration();

}


map::map(map const &other)  //copy constructor
{
	rows = other.rows;
	cols = other.cols;
	Map = new char*[rows];
	for (int i = 0; i < rows; i++)
		Map[i] = new char[cols];

	for(int i=0;i<rows;i++)
		for (int j = 0; j < cols; j++)
		{
			Map[i][j] = other.Map[i][j];
		}
}

void map::Setter()  //setter for columns and rows if wanted
{
	char Answer;
	cout << "Map dimension is 15x15, do you want to change it? type Y(yes) or N(no)"<<endl;
	cin >> Answer;
	if (Answer == 'Y' || Answer=='y')
	{
		int newrows, newcols;
		cout << "Rows: " << endl; cin >> newrows;
		cout << "Columns: " << endl; cin >> newcols;
		SetRows(newrows);
		SetCols(newcols); 
		/*i tried with map::~map() map(newrows,newcols but i get error at printmap*/


		for (int i = 0; i < rows; i++)
			delete[] Map[i];
		delete[] Map;

		Map = new char*[newrows];
		for (int i = 0; i < newrows; i++)
			Map[i] = new char[newcols];

		for (int i = 0; i < newrows; i++)
			for (int j = 0; j < newcols; j++)
				Map[i][j] = '-';

		TreasureGeneration();
	}
}

void map::PrintMap()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			cout << Map[i][j] << " ";
		cout << '\n';
	}
}

map::~map()
{
	for (int i = 0; i < rows; i++)
			delete[] Map[i];
	delete[] Map;
}

void map::SetAgentsPositions(int oldx,int oldy, int x, int y, agents *agent)
{
	Map[oldx][oldy] = '0';
	Map[x][y] = agent->ReturnName();
	cout << agent->ReturnName() << " has moved to " << x << " " << y << endl;
	

}
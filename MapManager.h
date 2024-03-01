#pragma once
#include "Manager.h"

#include "MapGrid.h"

#define MM MapManager::getInstance()

class MapManager : public df::Manager
{
private:
	MapManager();		        // Private (a singleton).    
	MapManager(MapManager const&);   // Don't allow copy.
	void operator=(MapManager const&);  // Don't allow assignment  
	int hero_cell_X;
	int hero_cell_Y;
	MapGrid* grid00;
	MapGrid* grid10;
	MapGrid* grid20;
	MapGrid* grid01;
	MapGrid* grid11;
	MapGrid* grid21;
	MapGrid* grid02;
	MapGrid* grid12;
	MapGrid* grid22;

public:
	// Get the one and only instance of the Map Manager.
	static MapManager& getInstance();

	//get the hero cell X
	int getCellX() const;

	//get the hero cell Y
	int getCellY() const;

	//set the hero cells
	void setCellXY(int x, int y);
	
	//Create the 9 cells and set their sprites/collision boxes.
	void createWorld();

	//Create the enemies in the world
	void spawnEnemies();
};


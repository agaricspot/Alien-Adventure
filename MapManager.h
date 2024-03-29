#pragma once
#include "Manager.h"


#define MM MapManager::getInstance()

class MapManager : public df::Manager
{
private:
	MapManager();		        // Private (a singleton).    
	MapManager(MapManager const&);   // Don't allow copy.
	void operator=(MapManager const&);  // Don't allow assignment  
	int hero_cell_X;
	int hero_cell_Y;

public:
	// Get the one and only instance of the Map Manager.
	static MapManager& getInstance();

	//get the hero cell X
	int getCellX();

	//get the hero cell Y
	int getCellY();

	//get the hero cell X
	int setCellX(df::Vector pos);

	//get the hero cell Y
	int setCellY(df::Vector pos);

	//set the hero cells
	void setCellXY();
	
	//Create the 9 cells and set their sprites/collision boxes.
	void createWorld();

	//Create the enemies in the world
	void spawnEnemies();
};


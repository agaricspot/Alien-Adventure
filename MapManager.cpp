#include "MapManager.h"
#include "EnvironmentObject.h"

#include "WorldManager.h"
#include "DisplayManager.h"

MapManager::MapManager() {
	hero_cell_X = 0;
	hero_cell_Y = 1;
}

MapManager& MapManager::getInstance() {
	static MapManager m_m;
	return m_m;
}

//get the hero cell X
int MapManager::getCellX() const {
	return hero_cell_X;
}

//get the hero cell Y
int MapManager::getCellY() const {
	return hero_cell_Y;
}

//set the hero cells
void MapManager::setCellXY(int x, int y) {
	hero_cell_X = x;
	hero_cell_Y = y;
	if (x == 0 && y == 0) {
		df::Box init_view(df::Vector(0, 0), 80, 24);
		WM.setView(init_view);
	}
	if (x == 1 && y == 0) {
		df::Box init_view(df::Vector(80, 0), 80, 24);
		WM.setView(init_view);
	}
	if (x == 2 && y == 0) {
		df::Box init_view(df::Vector(160, 0), 80, 24);
		WM.setView(init_view);
	}
	if (x == 0 && y == 1) {
		df::Box init_view(df::Vector(0, 24), 80, 24);
		WM.setView(init_view);
	}
	if (x == 1 && y == 1) {
		df::Box init_view(df::Vector(80, 24), 80, 24);
		WM.setView(init_view);
	}
	if (x == 2 && y == 1) {
		df::Box init_view(df::Vector(160, 24), 80, 24);
		WM.setView(init_view);
	}
	if (x == 0 && y == 2) {
		df::Box init_view(df::Vector(0, 48), 80, 24);
		WM.setView(init_view);
	}
	if (x == 1 && y == 2) {
		df::Box init_view(df::Vector(80, 48), 80, 24);
		WM.setView(init_view);
	}
	if (x == 2 && y == 2) {
		df::Box init_view(df::Vector(160, 48), 80, 24);
		WM.setView(init_view);
	}
}

//Create the world
void MapManager::createWorld() {
	//Place all the map sprites and name them
	grid00 = new MapGrid(0, 0, 0);

	grid10 = new MapGrid(1, 0, 1);

	grid20 = new MapGrid(2, 0, 2);

	grid01 = new MapGrid(0, 1, 3);

	grid11 = new MapGrid(1, 1, 4);

	grid21 = new MapGrid(2, 1, 5);

	grid02 = new MapGrid(0, 2, 6);

	grid12 = new MapGrid(1, 2, 7);

	grid22 = new MapGrid(2, 2, 8);

	EnvironmentObject::makeSpaceship("Door");

	new df::Box(df::Vector(0, 18), 25, 9);
}
#include "MapManager.h"
#include "EnvironmentObject.h"

#include "WorldManager.h"
#include "DisplayManager.h"

#include <iostream>

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

	EnvironmentObject::makeSpaceship("Wall");
	
	EnvironmentObject::makeRock("Wall", df::Vector(78, 22), 1);
}
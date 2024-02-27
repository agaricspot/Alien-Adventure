#include "MapManager.h"

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
}

//Create the world
void MapManager::createWorld() {

}
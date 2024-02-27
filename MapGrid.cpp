#include "MapGrid.h"

MapGrid::MapGrid(int x, int y) {
	setType("MapCell");
	setSprite("cave");
	setAltitude(0);
	setCoord(x, y);
	setSolidness(df::SPECTRAL);
	setPosition(df::Vector(39, 36));
}

void MapGrid::setCoord(int x, int y) {
	x_coord = x;
	y_coord = y;
}

//Return x location of map cell
int MapGrid::getX() const {
	return x_coord;
}

//Return y location of map cell
int MapGrid::getY() const {
	return y_coord;
}

//Event handler (detect hero entering, switch view location)
int MapGrid::eventHandler(const df::Event* p_e) {
	return 0;
}

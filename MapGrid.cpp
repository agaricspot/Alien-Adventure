#include "MapGrid.h"

MapGrid::MapGrid(int x, int y, int num) {
	setType("MapCell");
	setAltitude(0);
	setCoord(x, y);
	setSolidness(df::SPECTRAL);
	setPosition(df::Vector(39 + (80 * x), 11 + (24* y)));
	switch (num) {
	case 0:
		setSprite("cave");
		break;
	case 1:
		setSprite("woods");
		break;
	case 2:
		setSprite("clearing");
		break;
	case 3:
		setSprite("landing");
		break;
	case 4:
		setSprite("circle");
		break;
	case 5:
		setSprite("field");
		break;
	case 6:
		setSprite("field");
		break;
	case 7:
		setSprite("woods");
		break;
	case 8:
		setSprite("nest");
		break;
	}
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

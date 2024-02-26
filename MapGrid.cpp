#include "MapGrid.h"

MapGrid::MapGrid(int x, int y) {
	setType("MapCell");
	setCoord(x, y);
}

void MapGrid::setCoord(int x, int y) {
	x_coord = x;
	y_coord = y;
}

//Return x location of map cell
int getX() const;

//Return y location of map cell
int getY() const;

//Event handler (detect hero entering, switch view location)
int eventHandler(const df::Event* p_e) override;
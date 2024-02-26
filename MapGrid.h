#pragma once
#include "Object.h"

class MapGrid : public df::Object
{
private:
	int x_coord;
	int y_coord;

public:
	//Make a grid, set to spectral, and set the sprite.
	MapGrid(int x, int y);

	//Set the location of the map cell
	void setCoord(int x, int y);

	//Return x location of map cell
	int getX() const;

	//Return y location of map cell
	int getY() const;

	//Event handler (detect hero entering, switch view location)
	int eventHandler(const df::Event* p_e) override;
};


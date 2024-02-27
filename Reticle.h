#pragma once
#include "Object.h"

#define RETICLE_CHAR '+'

class Reticle : public df::Object {
private:
	void setMapCellX();
	void setMapCellY();

	int mapCellX;
	int mapCellY;

public:
	Reticle();
	int draw() override;
	int eventHandler(const df::Event* p_e) override;
};


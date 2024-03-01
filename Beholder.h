#pragma once
#include "Enemy.h"

class Beholder : public Enemy
{
private:
	bool isMoving;
	bool active = false;

public:
	Beholder();

	int eventHandler(const df::Event* p_e) override;

};


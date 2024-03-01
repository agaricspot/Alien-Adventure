#pragma once
#include "Enemy.h"

class Beholder : public Enemy
{
private:
	bool isMoving;

public:
	Beholder();

	int eventHandler(const df::Event* p_e) override;

};


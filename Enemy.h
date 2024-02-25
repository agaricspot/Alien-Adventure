#pragma once
#include "Object.h"

class Enemy : public df::Object
{
private:
	// Health and damage disable for the moment
	//int health;
	//int damage;

	int attack_slowdown = 35;
	int attack_countdown = attack_slowdown;

	virtual void track();

public:
	Enemy();
	~Enemy();

	int eventHandler(const df::Event* p_e) override;

	//Detect the distance to the hero
	float detectDistance();

	//If within a few spaces, attack
	int attack();
};


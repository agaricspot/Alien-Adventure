#include "Enemy.h"
#include "Hero.h"
#include "EventDamage.h"

#include "EventStep.h"
#include "WorldManager.h"
#include "ObjectList.h"
#include "DisplayManager.h"

#include <iostream>

Enemy::Enemy() {
	setType("Enemy");
	registerInterest(df::STEP_EVENT);
	setSprite("goopling");
	setPosition(df::Vector(0, 48));
	setSpeed(0.15);
}

Enemy::~Enemy() {
	//destroy the enemy
}

//Track the hero and set the direction towards them.
void Enemy::track() {
	df::ObjectList heroList = WM.objectsOfType("Hero");
	if (heroList.isEmpty()) {
		setVelocity(df::Vector(0, 0));
		return;
	}
	df::Object* hero = heroList[0];

	df::Vector e_pos = getPosition();
	df::Vector h_pos = hero->getPosition();

	df::Vector seek = h_pos - e_pos;
	seek.normalize();
	seek.scale(getSpeed());
	setVelocity(df::Vector(seek.getX(), seek.getY()));
}

//Handle step events. Currently the enemy doesn't need anything else.
int Enemy::eventHandler(const df::Event* p_e) {
	if (p_e->getType() == df::STEP_EVENT) {
		attack_countdown--;
		if (attack_countdown < 0) {
			attack_countdown = 0;
		}
		track();
		if (detectDistance() < 0) {
			return -1;
		}
		if(detectDistance() < 5)
			attack();
		return 1;
	}
	if (p_e->getType() == DAMAGE_EVENT) {
		//delete when it gets hit
		WM.markForDelete(this);
	}
	return 0;
}

//Calculate the distance from the enemy to the hero.
float Enemy::detectDistance() {
	df::ObjectList heroList = WM.objectsOfType("Hero");
	if (heroList.isEmpty()) {
		return -1;
	}
	df::Object* hero = heroList[0];

	df::Vector e_pos = getPosition();
	df::Vector h_pos = hero->getPosition();

	df::Vector diff = h_pos - e_pos;
	float distance = diff.getMagnitude();
	return distance;
}

//If the hero is close, attack. This is a melee attack for now.
int Enemy::attack() {
	if (attack_countdown > 0)
		return -1;
	attack_countdown = attack_slowdown;
	std::cout << "Damage!" << std::endl;
	df::ObjectList heroList = WM.objectsOfType("Hero");
	df::Object* hero = heroList[0];
	EventDamage d(1);
	hero->eventHandler(&d);
	return d.getDamage();

}
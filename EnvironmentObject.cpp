#include "EnvironmentObject.h"

#include "EventCollision.h"
#include "ObjectList.h"
#include "WorldManager.h"
#include "Hero.h"

#include <iostream>

// Generic constructor for an environment object. Private. Only called via the makeFoo methods
EnvironmentObject::EnvironmentObject(std::string type, df::Vector pos) {
	setType(type);
	setPosition(pos);
	registerInterest(df::COLLISION_EVENT);
}

//Make a mushroom power up
EnvironmentObject* EnvironmentObject::makeMushroom(std::string type, df::Vector pos) {
	EnvironmentObject* eo = new EnvironmentObject(type, pos);
	eo->setSprite("mushroom");
	eo->setSolidness(df::SOFT);
	return eo;
}

//Make a flower
EnvironmentObject* EnvironmentObject::makeFlower(std::string type, df::Vector pos) {
	EnvironmentObject* eo = new EnvironmentObject(type, pos);
	eo->setSprite("flower");
	eo->setSolidness(df::SPECTRAL);
	return eo;
}

//Make the spaceship
EnvironmentObject* EnvironmentObject::makeSpaceship(std::string type) {
	EnvironmentObject* eo = new EnvironmentObject(type, df::Vector(10, 36));
	eo->setSprite("door");
	eo->setSolidness(df::HARD);
	return eo;
}

//Make a rock. Value for size in input
EnvironmentObject* EnvironmentObject::makeRock(std::string type, df::Vector pos, std::string sprite) {
	EnvironmentObject* eo = new EnvironmentObject(type, pos);
	eo->setSolidness(df::HARD);
	eo->setSprite(sprite);
	return eo;
}

//Make the egg
EnvironmentObject* EnvironmentObject::makeEgg(std::string type, df::Vector pos) {
	EnvironmentObject* eo = new EnvironmentObject(type, pos);
	eo->setSprite("egg");
	eo->setSolidness(df::SOFT);
	eo->setAltitude(1);
	return eo;
}

//Handle collisions
int EnvironmentObject::eventHandler(const df::Event* p_e){
	if (p_e->getType() == df::COLLISION_EVENT) {
		const df::EventCollision* p_keyboard_event = dynamic_cast <const df::EventCollision*> (p_e);
		if (getType() == "Egg") {
			df::ObjectList heroList = WM.objectsOfType("Hero");
			if (heroList.isEmpty()) {
				return -1;
			}
			Hero* hero = dynamic_cast <Hero*> (heroList[0]); // This is probably bad practice. But I Need it
			hero->setEgg(true);
		}
		return 1;
	}
	return 0;
}
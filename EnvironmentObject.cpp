#include "EnvironmentObject.h"

#include <iostream>

// Generic constructor for an environment object. Private. Only called via the makeFoo methods
EnvironmentObject::EnvironmentObject(std::string type, df::Vector pos) {
	setType(type);
	setPosition(pos);
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
EnvironmentObject* EnvironmentObject::makeRock(std::string type, df::Vector pos, int size) {
	EnvironmentObject* eo = new EnvironmentObject(type, pos);
	eo->setSolidness(df::HARD);
	eo->setSprite("bigrock");
	return eo;
}
#include "EnvironmentObject.h"


EnvironmentObject::EnvironmentObject(std::string type, df::Vector pos) {
	setType(type);
	setPosition(pos);
}

//Make a mushroom power up
EnvironmentObject* EnvironmentObject::makeMushroom(std::string type, df::Vector pos) {
	EnvironmentObject* eo = new EnvironmentObject(type, pos);
	eo->setSprite("mushroom");
	return eo;
}

//make a flower
EnvironmentObject* EnvironmentObject::makeFlower(std::string type, df::Vector pos) {
	EnvironmentObject* eo = new EnvironmentObject(type, pos);
	eo->setSprite("mushroom");
	return eo;
}

//Make the spaceship
EnvironmentObject* EnvironmentObject::makeSpaceship(std::string type) {
	EnvironmentObject* eo = new EnvironmentObject(type, df::Vector(10, 36));
	eo->setSprite("door");
	eo->setSolidness(df::HARD);
	return eo;
}
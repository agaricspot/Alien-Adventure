#pragma once
#include "Object.h"

class EnvironmentObject : public df::Object
{
private:
	EnvironmentObject(std::string type, df::Vector pos);

public:
	//Make a mushroom power up
	static EnvironmentObject* makeMushroom(std::string type, df::Vector pos);

	//make a flower
	static EnvironmentObject* makeFlower(std::string type, df::Vector pos);

	//Make the spaceship
	static EnvironmentObject* makeSpaceship(std::string type);

	//Make a rock. Value for size in input
	static EnvironmentObject* makeRock(std::string type, df::Vector pos, int size);
};


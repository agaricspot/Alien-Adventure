#pragma once
#include "Event.h"

#include <string>

const std::string DAMAGE_EVENT = "damage";

class EventDamage : public df::Event
{
private:
	int damage;

	//set the amount of damage from this event. Only used by constructor
	void setDamage(int d);

public:
	EventDamage(int d);

	//return the amount of damage from this event
	int getDamage() const;
};


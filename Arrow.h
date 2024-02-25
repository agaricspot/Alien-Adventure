#pragma once
#include "Object.h"

#include "EventCollision.h"

class Arrow : public df::Object
{
private:
	bool piercing;

public:
	Arrow(df::Vector pos, bool facing);

	int eventHandler(const df::Event* p_e);

	void out();

	void hit(const df::EventCollision* p_collision_event);

};


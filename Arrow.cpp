#include "Arrow.h"

#include "WorldManager.h"
#include "EventOut.h"
#include "EventDamage.h"

#include <iostream>

Arrow::Arrow(df::Vector pos, bool facing) {
	std::cout << "Made an arrow!" << std::endl;
	if (!facing) { //set sprite based on arrow direction. May add up/down later
		setSprite("arrowleft");
	}
	else {
		setSprite("arrowright");
	}
	setSolidness(df::SOFT);
	setAltitude(1);
	setType("Arrow");
	registerInterest(df::OUT_EVENT);
	registerInterest(df::COLLISION_EVENT);
	// Set starting location, based on hero's position passed in.
	df::Vector p(pos.getX() + 3, pos.getY());
	setPosition(p);
	// Bullets move 1 space each game loop.
	// The direction is set when the Hero fires.
	setSpeed(1);
	piercing = false;
}

int Arrow::eventHandler(const df::Event* p_e) {
	if (p_e->getType() == df::OUT_EVENT) {
		//The arrow left the screen
		out();
		return 1;
	}
	if (p_e->getType() == df::COLLISION_EVENT) {
		//The arrow hit something.
		const df::EventCollision* collision_event = dynamic_cast <const df::EventCollision*> (p_e);
		hit(collision_event);
		return 1;
	}
	if (p_e->getType() == DAMAGE_EVENT) {
		//If the arrow gets damaged, delete it, unless it has piercing
		if (!piercing) {
			WM.markForDelete(this);
		}
		return 1;
	}
	return 0;
}

void Arrow::out() {
	//Destroy the arrow if it leaves the window.
	WM.markForDelete(this);
}

void Arrow::hit(const df::EventCollision* collision_event) {
	if (piercing) {
		if ((collision_event->getObject1()->getType() == "Enemy")) {
			//create and send a damage event to the relevant objects
			std::cout << "Collided with enemy" << std::endl;
			EventDamage damage(1);
			collision_event->getObject1()->eventHandler(&damage);
		}
		else if ((collision_event->getObject2()->getType() == "Enemy")) {
			std::cout << "Collided with enemy" << std::endl;
			EventDamage damage(1);
			collision_event->getObject2()->eventHandler(&damage);
		}
	}
	else if ((collision_event->getObject1()->getType() == "Enemy") || (collision_event->getObject2()->getType() == "Enemy")) {
		std::cout << "Collided with enemy" << std::endl;
		EventDamage damage(1);
		collision_event->getObject1()->eventHandler(&damage);
		collision_event->getObject2()->eventHandler(&damage);
	}
	else if ((collision_event->getObject1()->getType() == "Wall") || (collision_event->getObject2()->getType() == "Wall")) {
		//Destroy the arrow if it hits a wall. No damage required.
		WM.markForDelete(this);
	}
}
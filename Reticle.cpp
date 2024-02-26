#include "Reticle.h"

#include "EventMouse.h"
#include "DisplayManager.h"
#include "WorldManager.h"

#include <iostream>

//Create a reticle for aiming arrows or sword direction
Reticle::Reticle() {
	//Set attributes
	setType("Reticle");
	setAltitude(df::MAX_ALTITUDE);
	setSolidness(df::SPECTRAL);
	//Register interest for mouse events
	registerInterest(df::MSE_EVENT);
	//Start in the middle of the screen
	df::Vector p(40, 56);
	setPosition(p);
}

//Draw the character on the screen in green.
int Reticle::draw() {
	return DM.drawCh(getPosition(), RETICLE_CHAR, df::GREEN);
}

//Follow the postion of the mouse across the screen.
int Reticle::eventHandler(const df::Event* p_e) {
	if (p_e->getType() == df::MSE_EVENT) {
		const df::EventMouse* mouse_event = dynamic_cast <const df::EventMouse*> (p_e);
		if (mouse_event->getMouseAction() == df::MOVED) {
			// Change location to new mouse position.
			df::Vector adjusted_pos(mouse_event->getMousePosition().getX() + (80 * 0), mouse_event->getMousePosition().getY() + (24 * 2));
			setPosition(adjusted_pos);
			//std::cout << "Mouse position: " << adjusted_pos.toString() <<std::endl;
			return 1;
		}
	}
}
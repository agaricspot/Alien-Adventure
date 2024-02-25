#include "Reticle.h"

#include "EventMouse.h"
#include "DisplayManager.h"
#include "WorldManager.h"

//Create a reticle for aiming arrows or sword direction
Reticle::Reticle() {
	//Set attributes
	setType("Reticle");
	setAltitude(df::MAX_ALTITUDE);
	setSolidness(df::SPECTRAL);
	//Register interest for mouse events
	registerInterest(df::MSE_EVENT);
	//Start in the middle of the screen
	int world_horizontal = (int)WM.getBoundary().getHorizontal();
	int world_vertical = (int)WM.getBoundary().getVertical();
	df::Vector p(world_horizontal / 2, world_vertical / 2);
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
			setPosition(mouse_event->getMousePosition());
			return 1;
		}
	}
}
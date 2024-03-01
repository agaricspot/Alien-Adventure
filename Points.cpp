#include "Points.h"

// make a points object that displays stuff
Points::Points() {
	setLocation(df::BOTTOM_LEFT);
	setViewString(POINTS_STRING);
	setColor(df::GREEN);
}

int Points::eventHandler(const df::Event* p_e) {
	// Parent handles event if score update.
	if (df::ViewObject::eventHandler(p_e)) {
		return 1;
	}
		// If get here, have ignored this event.
	return 0;
}
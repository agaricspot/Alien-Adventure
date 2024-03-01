#include "Beholder.h"
#include "EventDamage.h"
#include "MapManager.h"

#include "EventStep.h"
#include "ObjectList.h"
#include "WorldManager.h"


Beholder::Beholder() {
	setSprite("beholder");
	setSolidness(df::SOFT);
	isMoving = false;
	active = false;
	setPosition(df::Vector(215, 62));
}

int Beholder::eventHandler(const df::Event* p_e) {
	if (p_e->getType() == df::STEP_EVENT) {
		if (MM.getCellX() == 2 && MM.getCellY() == 2) {
			active = true;
		}
		const df::EventStep* step_event = dynamic_cast <const df::EventStep*> (p_e);
		if (step_event->getStepCount() % 90 == 0) {
			isMoving = !isMoving;
		}
		if (isMoving && active) {
			setSpeed(0.15f);
			track();
		}
		else {
			setSpeed(0.0f);
		}
		if (detectDistance() < 10) {
			df::ObjectList heroList = WM.objectsOfType("Hero");
			if (heroList.isEmpty()) {
				return 0;
			}
			df::Object* hero = heroList[0];
			EventDamage d(1);
			hero->eventHandler(&d);
		}
		return 1;
	}
	return 0;
}
#include "Hero.h"
#include "Arrow.h"
#include "EventDamage.h"
#include "MapManager.h"

#include "WorldManager.h"
#include "EventStep.h"
#include "EventOut.h"
#include "ObjectListIterator.h"

#include <iostream>


Hero::Hero() {
	setSprite("heroswordr");
	registerInterest(df::KEYBOARD_EVENT);
	registerInterest(df::STEP_EVENT);
	registerInterest(df::MSE_EVENT);
	registerInterest(df::OUT_EVENT);
	setType("Hero");
	df::Vector p(40, 36);
	setPosition(p);
	cur_weapon = SWORD;
	egg = false;
	MM.setCellXY();
}

Hero::~Hero() { //do nothing for now

	//Set the sprite to the dead hero
	//setSprite("dead");
	

	//new GameOver();
}

//Take input events - Keyboard for movement, mouse for shooting, and step for movement/shooting timing
int Hero::eventHandler(const df::Event* p_e) {
	if (p_e->getType() == df::KEYBOARD_EVENT) {
		const df::EventKeyboard* p_keyboard_event = dynamic_cast <const df::EventKeyboard*> (p_e);
		keyboard(p_keyboard_event);
		return 1;
	}
	if (p_e->getType() == df::STEP_EVENT) {
		step();
		return 1;
	}
	if (p_e->getType() == df::MSE_EVENT) {
		const df::EventMouse* p_mouse_event = dynamic_cast <const df::EventMouse*> (p_e);
		mouse(p_mouse_event);
		return 1;
	}
	if (p_e->getType() == DAMAGE_EVENT) {
		// If the hero gets damaged, remove it for now. May add health later.
		defeat();
		return 1;
	}
	if(p_e->getType() == df::OUT_EVENT) {
		// If the hero gets damaged, remove it for now. May add health later.
		std::cout << "left the world" << std::endl;
		return 1;
	}
	return 0;
}

// Movement via keyboard.
void Hero::keyboard(const df::EventKeyboard* keyboard_event) {
	switch (keyboard_event->getKey()) {
	case df::Keyboard::W:    // Up
		if (keyboard_event->getKeyboardAction() == df::KEY_DOWN)
			move(0, -1);
		break;
	case df::Keyboard::S:    // Down
		if (keyboard_event->getKeyboardAction() == df::KEY_DOWN)
			move(0, 1);
		break;
	case df::Keyboard::A:    // Left
		if (keyboard_event->getKeyboardAction() == df::KEY_DOWN) {
			move(-2, 0);
			switch (cur_weapon) {
			case BOW:
				setSprite("herobowl");
				break;
			case SWORD:
				setSprite("heroswordl");
				break;
			}
		}
		break;
	case df::Keyboard::D:    // Right
		if (keyboard_event->getKeyboardAction() == df::KEY_DOWN) {
			move(2, 0);
			switch (cur_weapon) {
			case BOW:
				setSprite("herobowr");
				break;
			case SWORD:
				setSprite("heroswordr");
				break;
			}
		}
		break;
	}
}

// Mouse clicks. This fires the weapon with left click
void Hero::mouse(const df::EventMouse* mouse_event) {
	//std::cout << "Map cell: " << MM.getCellX() << ", " << MM.getCellY() << std::endl;
	if ((mouse_event->getMouseAction() == df::CLICKED) && (mouse_event->getMouseButton() == df::Mouse::LEFT)) {
		df::Vector adjusted_pos(mouse_event->getMousePosition().getX() + (80 * MM.getCellX()), mouse_event->getMousePosition().getY() + (24 * MM.getCellY()));
		attack(adjusted_pos, cur_weapon);
	}
	if ((mouse_event->getMouseAction() == df::CLICKED) && (mouse_event->getMouseButton() == df::Mouse::RIGHT)) {
		switch (cur_weapon) {
		case SWORD:
			cur_weapon = BOW;
			setSprite("herobowr");
			break;
		case BOW:
			cur_weapon = SWORD;
			setSprite("heroswordr");
			break;
		}
	}
}

void Hero::step() {
	// Slow down movement to 1 per 5 steps
	move_countdown--;
	if (move_countdown < 0)
		move_countdown = 0;

	arrow_countdown--;
	if (arrow_countdown < 0){
		arrow_countdown = 0;
	}
	MM.setCellX(getPosition());
	MM.setCellY(getPosition());
	MM.setCellXY();
}

void Hero::attack(df::Vector target, WEAPON weapon) {
	if (weapon == BOW) {
		if (arrow_countdown > 0)
			return;
		arrow_countdown = arrow_slowdown;
		// Fire Bullet towards target.
	  // Compute normalized vector to position, then scale by speed (1).
		df::Vector v = target - getPosition();
		v.normalize();
		v.scale(1);
		bool direction = (target.getX() > getPosition().getX());
		Arrow* p = new Arrow(getPosition(), direction);
		p->setVelocity(v);
	} 
	else if (weapon == SWORD) {
		//Look at all objects
		df::ObjectList all = WM.getAllObjects();
		df::ObjectListIterator li(&all);
		while (!li.isDone()) {
			//If they're within 4 distance
			if (detectDistance(li.currentObject()) < 10 && li.currentObject()->getType() != "Hero") {
				//Give them a damage event. This makes the sword a sweep attack. I'm fine with that.
				EventDamage damage(1);
				li.currentObject()->eventHandler(&damage);
			}
			li.next();
		}
	}
}

void Hero::move(int dx, int dy) {
	// See if time to move.
	if (move_countdown > 0)
		return;
	move_countdown = move_slowdown;

	// If stays on window, allow move.
	df::Vector new_pos(getPosition().getX() + dx, getPosition().getY() + dy);
	WM.moveObject(this, new_pos);
}

// Sequence of actions to do when the hero dies. For now, just remove the hero.
void Hero::defeat() {
	//Dead sprite, stuff, etc.
	WM.markForDelete(this);
}

float Hero::detectDistance(Object *other) const{

	df::Vector o_pos = other->getPosition();
	df::Vector h_pos = getPosition();

	df::Vector diff = o_pos - h_pos;
	float distance = diff.getMagnitude();
	return distance;
}

//set the egg value
void Hero::setEgg(bool hasegg) {
	egg = hasegg;
}
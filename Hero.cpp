#include "Hero.h"
#include "Arrow.h"
#include "EventDamage.h"

#include "WorldManager.h"
#include "EventStep.h"


Hero::Hero() {
	setSprite("hero");
	registerInterest(df::KEYBOARD_EVENT);
	registerInterest(df::STEP_EVENT);
	registerInterest(df::MSE_EVENT);
	setType("Hero");
	df::Vector p(WM.getBoundary().getHorizontal() / 2, WM.getBoundary().getVertical() / 2);
	setPosition(p);
	cur_weapon = BOW;
}

Hero::~Hero() { //do nothing for now
	// Mark Reticle for deletion.
	//WM.markForDelete(p_reticle);
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
	return 0;
}

// Movement via keyboard.
void Hero::keyboard(const df::EventKeyboard* keyboard_event) {
	switch (keyboard_event->getKey()) {
	case df::Keyboard::W:    // up
		if (keyboard_event->getKeyboardAction() == df::KEY_DOWN)
			move(0, -1);
		break;
	case df::Keyboard::S:    // down
		if (keyboard_event->getKeyboardAction() == df::KEY_DOWN)
			move(0, 1);
		break;
	case df::Keyboard::A:    // Left
		if (keyboard_event->getKeyboardAction() == df::KEY_DOWN)
			move(-2, 0);
		break;
	case df::Keyboard::D:
		if (keyboard_event->getKeyboardAction() == df::KEY_DOWN) {
			move(2, 0);
		}
		break;
	}
}

// Mouse clicks. This fires the weapon with left click
void Hero::mouse(const df::EventMouse* mouse_event) {
		if ((mouse_event->getMouseAction() == df::CLICKED) &&
			(mouse_event->getMouseButton() == df::Mouse::LEFT))
			attack(mouse_event->getMousePosition(), cur_weapon);

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
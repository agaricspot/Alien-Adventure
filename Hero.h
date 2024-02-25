#pragma once
#include "Object.h"
#include "Event.h"
#include "EventKeyboard.h"
#include "EventMouse.h"

enum WEAPON {
	SWORD,
	BOW,
};

class Hero : public df::Object
{
private:
	int arrow_count;
	WEAPON cur_weapon;

	void move(int dx, int dy);
	void keyboard(const df::EventKeyboard* keyboard_event);
	void mouse(const df::EventMouse* mouse_event);
	void attack(df::Vector pos, WEAPON weapon);
	void step();
	void defeat();

	int move_slowdown = 3;
	int move_countdown = move_slowdown;

	int arrow_slowdown = 45;
	int arrow_countdown = arrow_countdown;

public:
	Hero();
	~Hero();
	int eventHandler(const df::Event* p_e) override;
};


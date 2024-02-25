#include "EventDamage.h"

EventDamage::EventDamage(int d) {
	setType("DamageEvent");
	setDamage(d);
}

int EventDamage::getDamage() const {
	return damage;
}

void EventDamage::setDamage(int d) {
	damage = d;
}
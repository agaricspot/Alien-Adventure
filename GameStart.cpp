#include "GameStart.h"
#include "Hero.h"
#include "Reticle.h"
#include "MapManager.h"
#include "Points.h"

#include "EventKeyboard.h"
#include "GameManager.h"

GameStart::GameStart() {
	setType("GameStart");
	setSprite("start");
	setPosition(df::Vector(40, 36));
    registerInterest(df::KEYBOARD_EVENT);
}

int GameStart::eventHandler(const df::Event* p_e) {

    if (p_e->getType() == df::KEYBOARD_EVENT) {
        df::EventKeyboard* p_keyboard_event = (df::EventKeyboard*)p_e;
        switch (p_keyboard_event->getKey()) {
        case df::Keyboard::P: 			// play
            start();
            break;
        case df::Keyboard::Q:			// quit
            GM.setGameOver();
            break;
        default: // Key is not handled.
            break;
        }
        return 1;
    }

    // If get here, have ignored this event.
    return 0;
}

void GameStart::start() {
    new Hero();

    new Reticle();

    MM.createWorld();

    MM.spawnEnemies();

    new Points();

    setActive(false);
}

int GameStart::draw() {
    return df::Object::draw();
}
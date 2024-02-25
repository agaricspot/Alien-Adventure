//
// game.cpp
// 

// Engine includes.
#include "GameManager.h"
#include "LogManager.h"
#include "ResourceManager.h"


// Game code includes
#include "Hero.h"
#include "Reticle.h"
#include "Enemy.h"

void loadResources();

int main(int argc, char* argv[]) {

    // Start up game manager.
    df::GameManager& game_manager = df::GameManager::getInstance();
    if (game_manager.startUp()) {
        df::LogManager& log_manager = df::LogManager::getInstance();
        log_manager.writeLog("Error starting game manager!");
        game_manager.shutDown();
        return 0;
    }
    //turn to FALSE to publish game
    LM.setFlush(true);

    // Show splash screen.
    df::splash();
    
    loadResources();

    new Hero();
    new Reticle();

    new Enemy();

    GM.run();


    // Shut everything down.
    game_manager.shutDown();
    return 0;
}

void loadResources() {
    //This will load sprites once I have them.
    RM.loadSprite("sprites/hero-spr.txt", "hero");
    RM.loadSprite("sprites/arrowleft-spr.txt", "arrowleft");
    RM.loadSprite("sprites/arrowright-spr.txt", "arrowright");
    RM.loadSprite("sprites/enemy-spr.txt", "enemy");
}
//
// game.cpp
// 

#include <iostream>

// Engine includes.
#include "GameManager.h"
#include "LogManager.h"
#include "ResourceManager.h"
#include "WorldManager.h"
#include "DisplayManager.h"


// Game code includes
#include "Hero.h"
#include "Reticle.h"
#include "Enemy.h"
#include "MapGrid.h"
#include "MapManager.h"

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

    //Set the world size to a larger world.
    df::Box world_size = WM.getBoundary();
    world_size.setHorizontal(240);
    world_size.setVertical(72);
    WM.setBoundary(world_size);
    std::cout << "X: " << world_size.getHorizontal() << " Y: " << world_size.getVertical() << std::endl;
    //Set the view to the left center
    df::Box init_view(df::Vector(0, 24), 80, 24);
    WM.setView(init_view);

    
    loadResources();

    new Hero();

    new Reticle();

    new Enemy();

    MM.createWorld();

    GM.run();


    // Shut everything down.
    game_manager.shutDown();
    return 0;
}

void loadResources() {

    //Hero Sprites
    RM.loadSprite("sprites/hero_bow.txt", "herobowr");
    RM.loadSprite("sprites/hero_sword.txt", "heroswordr");
    RM.loadSprite("sprites/hero_bow_left.txt", "herobowl");
    RM.loadSprite("sprites/hero_sword_left.txt", "heroswordl");


    //Enemy Sprites
    RM.loadSprite("sprites/chomper.txt", "chomper");
    RM.loadSprite("sprites/goopling.txt", "goopling");
    
    //Misc Sprites
    RM.loadSprite("sprites/arrowleft.txt", "arrowleft");
    RM.loadSprite("sprites/arrowright.txt", "arrowright");
    
    //Environment Sprites
    RM.loadSprite("sprites/flower1.txt", "flower");
    RM.loadSprite("sprites/flower2.txt", "flower2");
    RM.loadSprite("sprites/space_station.txt", "door");
    RM.loadSprite("spretes/mushroom.txt", "mushroom");

    //Not needed right now
    RM.loadSprite("sprites/landing-0-1.txt", "landing");
    RM.loadSprite("sprites/cave-0-0.txt", "cave");
}
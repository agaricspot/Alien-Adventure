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
#include "MapManager.h"
#include "Points.h"

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

    MM.createWorld();

    MM.spawnEnemies();

    new Points();

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
    RM.loadSprite("sprites/spectator_boss.txt", "beholder");

    //Misc Sprites
    RM.loadSprite("sprites/arrowleft.txt", "arrowleft");
    RM.loadSprite("sprites/arrowright.txt", "arrowright");
    RM.loadSprite("sprites/egg.txt", "egg");

    //Environment Sprites
    RM.loadSprite("sprites/flower1.txt", "flower");
    RM.loadSprite("sprites/flower2.txt", "flower2");
    RM.loadSprite("sprites/mushroom.txt", "mushroom");

    RM.loadSprite("sprites/rock_big.txt", "bigrock");
    RM.loadSprite("sprites/rock_small.txt", "smallrock");
    RM.loadSprite("sprites/rock-b1.txt", "hwall1");
    RM.loadSprite("sprites/rock-b2.txt", "hwall2");
    RM.loadSprite("sprites/rock-vert1.txt", "vwall1");
    RM.loadSprite("sprites/rock-vert2.txt", "vwall2");

    RM.loadSprite("sprites/tree.txt", "tree");
    RM.loadSprite("sprites/tree-vert-b.txt", "talltree");
    RM.loadSprite("sprites/tree-1.txt", "tree1");
    RM.loadSprite("sprites/tree-dense.txt", "treedense");
    RM.loadSprite("sprites/misc-grass-1.txt", "grass1");
    RM.loadSprite("sprites/misc-grass-2.txt", "grass2");
    RM.loadSprite("sprites/misc-grass-3.txt", "grass3");

    RM.loadSprite("sprites/space_station.txt", "door");
}
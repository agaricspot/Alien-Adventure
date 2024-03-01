#include "MapManager.h"
#include "EnvironmentObject.h"
#include "Enemy.h"
#include "Beholder.h"

#include "WorldManager.h"
#include "DisplayManager.h"

#include <iostream>

MapManager::MapManager() {
	hero_cell_X = 0;
	hero_cell_Y = 1;
}

MapManager& MapManager::getInstance() {
	static MapManager m_m;
	return m_m;
}

//get the hero cell X
int MapManager::getCellX() const {
	return hero_cell_X;
}

//get the hero cell Y
int MapManager::getCellY() const {
	return hero_cell_Y;
}

//set the hero cells. This just does math to see where the hero is each step.
void MapManager::setCellXY(int x, int y) {
	hero_cell_X = x;
	hero_cell_Y = y;
	if (x == 0 && y == 0) {
		df::Box init_view(df::Vector(0, 0), 80, 24);
		WM.setView(init_view);
	}
	if (x == 1 && y == 0) {
		df::Box init_view(df::Vector(80, 0), 80, 24);
		WM.setView(init_view);
	}
	if (x == 2 && y == 0) {
		df::Box init_view(df::Vector(160, 0), 80, 24);
		WM.setView(init_view);
	}
	if (x == 0 && y == 1) {
		df::Box init_view(df::Vector(0, 24), 80, 24);
		WM.setView(init_view);
	}
	if (x == 1 && y == 1) {
		df::Box init_view(df::Vector(80, 24), 80, 24);
		WM.setView(init_view);
	}
	if (x == 2 && y == 1) {
		df::Box init_view(df::Vector(160, 24), 80, 24);
		WM.setView(init_view);
	}
	if (x == 0 && y == 2) {
		df::Box init_view(df::Vector(0, 48), 80, 24);
		WM.setView(init_view);
	}
	if (x == 1 && y == 2) {
		df::Box init_view(df::Vector(80, 48), 80, 24);
		WM.setView(init_view);
	}
	if (x == 2 && y == 2) {
		df::Box init_view(df::Vector(160, 48), 80, 24);
		WM.setView(init_view);
	}
}

//Create the world
void MapManager::createWorld(){
	//Place all the map sprites and name them

	EnvironmentObject::makeSpaceship("Wall");
	
	EnvironmentObject::makeRock("Wall", df::Vector(78, 22), "bigrock");

	//0-0 top wall
	for (int i = 0; i < 10; i++) {
		if (i % 2 == 0) {
			EnvironmentObject::makeRock("Wall", df::Vector((9 * i), 0), "hwall1");
			continue;
		}
		EnvironmentObject::makeRock("Wall", df::Vector((9 * i), 1), "hwall2");
	}

	//0-0 left wall
	for (int i = 0; i < 3; i++){
		if (i % 2 == 0) {
			EnvironmentObject::makeRock("Wall", df::Vector(1, (8 * i) + 4), "vwall1");
			continue;
		}
		EnvironmentObject::makeRock("Wall", df::Vector(1, (8 * i) + 4), "vwall2");
	}

	//Full Top wall
	for (int i = 0; i < 20; i++) {
		if (i % 2 == 0) {
			EnvironmentObject::makeRock("Wall", df::Vector((9 * i) + 80, 1), "tree1");
			continue;
		}
		EnvironmentObject::makeRock("Wall", df::Vector((9 * i) + 80, 0), "treedense");
	}

	//Right wall
	for (int i = 0; i < 6; i++) {
		if (i % 2 == 0) {
			EnvironmentObject::makeRock("Wall", df::Vector(238, (9 * i) + 4), "tree");
			continue;
		}
		EnvironmentObject::makeRock("Wall", df::Vector(235, (9 * i) + 4), "talltree");
	}

	//0-2 left wall
	for (int i = 0; i < 3; i++) {
		if (i % 2 == 0) {
			EnvironmentObject::makeRock("Wall", df::Vector(1, (8 * i) + 52), "tree");
			continue;
		}
		EnvironmentObject::makeRock("Wall", df::Vector(1, (8 * i) + 52), "talltree");
	}

	//Full lower wall
	for (int i = 0; i < 30; i++) {
		if (i % 2 == 0) {
			EnvironmentObject::makeRock("Wall", df::Vector((9 * i) , 70), "hwall1");
			continue;
		}
		EnvironmentObject::makeRock("Wall", df::Vector((9 * i), 71), "hwall2");
	}

	//Trees
	EnvironmentObject::makeRock("Wall", df::Vector(92, 54), "tree");      ///bottom center
	EnvironmentObject::makeRock("Wall", df::Vector(140, 65), "tree");     /// bottom center
	EnvironmentObject::makeRock("Wall", df::Vector(228, 6), "talltree");  /// top right
	EnvironmentObject::makeRock("Wall", df::Vector(180, 17), "tree");     /// top right
	EnvironmentObject::makeRock("Wall", df::Vector(120, 16), "talltree"); /// top center
	EnvironmentObject::makeRock("Wall", df::Vector(66, 33), "talltree");

	//flowers/grass
	


	//add random rocks
	EnvironmentObject::makeRock("Wall", df::Vector(30, 14), "smallrock"); /// topleft
	EnvironmentObject::makeRock("Wall", df::Vector(65, 64), "smallrock"); /// bottom left
	EnvironmentObject::makeRock("Wall", df::Vector(25, 50), "smallrock"); /// bottom left
	EnvironmentObject::makeRock("Wall", df::Vector(62, 40), "smallrock"); /// middle left
	EnvironmentObject::makeRock("Wall", df::Vector(69, 46), "smallrock"); /// middle left

	EnvironmentObject::makeRock("Wall", df::Vector(85, 20), "smallrock"); /// top center
	EnvironmentObject::makeRock("Wall", df::Vector(145, 5), "smallrock"); /// top center

	EnvironmentObject::makeRock("Wall", df::Vector(183, 37), "smallrock");/// middle right
	EnvironmentObject::makeRock("Wall", df::Vector(194, 39), "smallrock");/// middle right
	 
	// TODO : add mushroom powerups
}

//Create enemies
void MapManager::spawnEnemies() {
	Enemy::spawnEnemy("goopling", df::Vector(15, 5));     // top left
	Enemy::spawnEnemy("goopling", df::Vector(56, 5));     // top left
	Enemy::spawnEnemy("goopling", df::Vector(120, 8));    // top center
	Enemy::spawnEnemy("goopling", df::Vector(210, 5));    // top right
	Enemy::spawnEnemy("goopling", df::Vector(215, 18));   // top right
	Enemy::spawnEnemy("goopling", df::Vector(15, 55));    // bottom left
	Enemy::spawnEnemy("goopling", df::Vector(38, 66));    // bottom left

	Enemy::spawnEnemy("chomper", df::Vector(120, 60));    // bottom middle
	Enemy::spawnEnemy("chomper", df::Vector(200, 36));

	new Beholder();
}
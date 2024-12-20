#pragma once
#include "raylib.h"
#include "player.h"
#include "enemy.h"
#include "map.h"
#include <vector>
#include <iostream>

class Game
{
private:
	Player* player;
	Map* map;
	std::vector<Enemy*> enemies;

public:

	Game();
	~Game();

	void handleTextures();
	void update();
	void draw() const;
	void clear();

};
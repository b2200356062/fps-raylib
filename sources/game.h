#pragma once

#include "raylib.h"
#include "raygui.h"
#include "player.h"
#include "enemy.h"
#include "map.h"
#include "ui.h"

#include <iostream>
#include <vector>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define WINDOW_TITLE "FPS"

class Game
{
private:
	UI* ui = nullptr;
	Player* player = nullptr;
	Map* map = nullptr;
	std::vector<Enemy*> enemies;
	Camera3D camera;
	int frameCounter;
	UI::Scene currentScene;

public:

	Game();
	~Game();

	void init();
	void handleTextures();
	void update();
	void draw() const;
};
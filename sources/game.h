#pragma once

#include "raylib.h"
#include "raygui.h"
#include "player.h"
#include "enemy.h"
#include "map.h"
#include "ui.h"
#include "pickables.h"

constexpr auto SCREEN_WIDTH = 800;
constexpr auto SCREEN_HEIGHT = 600;
constexpr auto WINDOW_TITLE = "FPS";

class Game
{
private:
	Ui* ui = nullptr;
	Map* map = nullptr;
	Player* player = nullptr;

	std::vector<Enemy*> enemies;
	Camera3D camera;
	int frameCounter;
	
public:

	Game();
	~Game();

	void initGameplay();
	void update();

};
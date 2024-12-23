#pragma once

#include "raylib.h"
#include "raygui.h"
#include "player.h"
#include "enemy.h"
#include "map.h"
// #include "ui.h"

constexpr auto SCREEN_WIDTH = 800;
constexpr auto SCREEN_HEIGHT = 600;
constexpr auto WINDOW_TITLE = "FPS";

typedef enum Scene
{
	SCENE_TITLE = 0,
	SCENE_GAMEPLAY,
	SCENE_OPTIONS
}Scene;

class Game
{
private:
	Player* player = nullptr;
	Map* map = nullptr;
	std::vector<Enemy*> enemies;
	Camera3D camera;
	int frameCounter;
	Scene currentScene;

public:

	Game();
	~Game();

	void initGameplay();
	void update();

};
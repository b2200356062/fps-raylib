#include "game.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

Game::Game()
{
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
	SetWindowState(FLAG_VSYNC_HINT);
	SetTargetFPS(144);

	ui = new UI();
	player = new Player({100.f, 100.f});

	enemies.push_back(new Enemy(1, 100, {2.f, 1.f, 2.f}, ASSETS_PATH"textures/characters/SoldierIdle.png"));
	enemies.push_back(new Enemy(2, 100, { 5.f, 1.f, 5.f }, ASSETS_PATH"textures/characters/ZombieIdle.png"));
	enemies.push_back(new Enemy(3, 100, { -2.f, 1.f, -2.f }, ASSETS_PATH"textures/characters/CommandoIdle.png"));

	map = new Map();
	
	camera = { 0 };
	frameCounter = 0;
	currentScene = UI::SCENE_TITLE;
}

Game::~Game()
{

	enemies.clear();
}

void Game::init()
{
	camera.position = Vector3{ 0.0f, 1.0f, 4.0f };    // Camera position
	camera.target = Vector3{ 0.0f, 1.0f, 0.0f };      // Camera looking at point
	camera.up = Vector3{ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
	camera.fovy = 60.0f;                              // Camera field-of-view Y
	camera.projection = CAMERA_PERSPECTIVE;
}

void Game::handleTextures()
{

}

void Game::update()
{
	while (!WindowShouldClose())
	{
		Vector2 mousePos = GetMousePosition();
		bool mousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

		UpdateCamera(&camera, CAMERA_FIRST_PERSON);

		BeginDrawing();
		ClearBackground(RAYWHITE);

		switch (currentScene) {

			case UI::SCENE_TITLE:
			{
				ui->UpdateScene(currentScene);
			}break;

			case UI::SCENE_GAMEPLAY:
			{
				ui->UpdateScene(currentScene);
				BeginMode3D(camera);
					DisableCursor();
					map->draw();

					for (auto& enemy : enemies) {
						enemy->draw(camera);
					}

				EndMode3D();

				player->draw();

			}break;

			case UI::SCENE_OPTIONS:
			{
				ui->UpdateScene(currentScene);

			}break;

			default: break;
		}
		EndDrawing();
	}
	CloseWindow();
}

void Game::draw() const
{

}
#include "game.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

Game::Game()
{
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
	SetTargetFPS(144);

	player = new Player({100.f, 100.f});
	enemies.push_back(new Enemy(1, 100, {200.f, 200.f}));
	map = new Map();
	camera = { 0 };
	frameCounter = 0;
	currentScene = TITLE;
}

Game::~Game()
{

}

void Game::init()
{
	camera.position = Vector3{ 0.0f, 2.0f, 4.0f };    // Camera position
	camera.target = Vector3{ 0.0f, 2.0f, 0.0f };      // Camera looking at point
	camera.up = Vector3{ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
	camera.fovy = 60.0f;                              // Camera field-of-view Y
	camera.projection = CAMERA_PERSPECTIVE;
	SetExitKey(KEY_NULL);
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

		switch (currentScene) {
			case TITLE:
			{
				
			}break;

			case GAMEPLAY:
			{
				DisableCursor();
				player->update();

			}break;
		
			case OPTIONS:
			{

			}break;

			case CREDITS:
			{

			}break;
			default: break;
		}

		BeginDrawing();
		ClearBackground(RAYWHITE);

		switch (currentScene) {
			case TITLE:
			{
			
				DrawText("RETRO FPS", SCREEN_WIDTH / 3, SCREEN_HEIGHT / 8, 40, BLACK);

				bool startclicked = GuiButton(Rectangle{ SCREEN_WIDTH / 2 - 50, SCREEN_HEIGHT / 4, 100, 50 }, "START");
				bool optionsclicked = GuiButton(Rectangle{ SCREEN_WIDTH / 2 - 50, SCREEN_HEIGHT / 4 + 100, 100, 50 }, "OPTIONS");
				bool exitclicked = GuiButton(Rectangle{ SCREEN_WIDTH / 2 - 50, SCREEN_HEIGHT / 4 + 200, 100, 50 }, "EXIT");

				if (startclicked) currentScene = GAMEPLAY;
				if (optionsclicked) currentScene = OPTIONS;
				
			}break;

			case GAMEPLAY:
			{
				DisableCursor();
				draw();
				if (IsKeyDown(KEY_ESCAPE)) currentScene = OPTIONS;
			}break;

			case OPTIONS:
			{
				// EnableCursor();
				if (IsKeyDown(KEY_ESCAPE)) currentScene = GAMEPLAY;

			}break;

			case CREDITS:
			{

			}break;
			default: break;
		}

		EndDrawing();
	}

	CloseWindow();
}

void Game::draw() const
{
	// map draw
	player->draw();
	// enemy draw
	// gun draw
	
	/*for (auto& e : enemies) {
		e->draw();
	}*/
}
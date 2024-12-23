
#include "game.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#include <iostream>
#include <vector>

Game::Game()
{
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
	SetWindowState(FLAG_VSYNC_HINT);
	SetTargetFPS(144);
	camera = { 0 };
	frameCounter = 0;
	currentScene = SCENE_TITLE;
}

Game::~Game()
{
	enemies.clear();
}

void Game::initGameplay()
{
	map = new Map();

	player = new Player({ 100.f, 100.f });

	enemies.push_back(new Enemy(1, 100, { 2.f, 1.f, 2.f }, ASSETS_PATH"textures/characters/SoldierIdle.png"));
	enemies.push_back(new Enemy(2, 100, { 5.f, 1.f, 5.f }, ASSETS_PATH"textures/characters/ZombieIdle.png"));
	enemies.push_back(new Enemy(3, 100, { -2.f, 1.f, -2.f }, ASSETS_PATH"textures/characters/CommandoIdle.png"));

	
	
	

	camera.position = Vector3{ 0.0f, 1.0f, 4.0f };   
	camera.target = Vector3{ 0.0f, 1.0f, 0.0f };     
	camera.up = Vector3{ 0.0f, 1.0f, 0.0f };          
	camera.fovy = 60.0f;                              
	camera.projection = CAMERA_PERSPECTIVE;
}

void Game::update()
{
	// one time inits for camera, player, enemies etc.
	initGameplay();
	
	while (!WindowShouldClose())
	{
		Vector2 mousePos = GetMousePosition();
		bool mousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

		// update
		switch (currentScene) {

			//case SCENE_TITLE:
			//{
			//	
			//}
			//break;

			case SCENE_GAMEPLAY:
			{
				UpdateCamera(&camera, CAMERA_FIRST_PERSON);
				// UPDATE PLAYER ENEMIES GUN MAP

				for (auto& enemy : enemies) {
					enemy->update();
				}

				player->update(enemies, camera);

				map->update();
			}
			break;

			//case SCENE_OPTIONS:
			//{


			//}
			//break;

			default: break;
		}

		// draw
		BeginDrawing();
		ClearBackground(RAYWHITE);

		switch (currentScene) 
		{
			case SCENE_TITLE:
			{
				DrawText("RETRO FPS", 200, 100, 40, DARKGRAY);

				if (GuiButton(Rectangle{ 200, 200, 200, 40 }, "START")) 
				{
					currentScene = SCENE_GAMEPLAY;
	            }
	            if (GuiButton(Rectangle{ 200, 260, 200, 40 }, "OPTIONS")) 
				{
					currentScene = SCENE_OPTIONS;
	            }
	            if (GuiButton(Rectangle{ 200, 320, 200, 40 }, "EXIT")) 
				{
					exit(0);
	            }
	            break;
			}
			break;

			case SCENE_GAMEPLAY:
			{
				BeginMode3D(camera);

					DisableCursor();

					map->draw();

					for (auto& enemy : enemies) {
						enemy->draw(camera);
					}

				EndMode3D();

				player->draw();
			}
			break;

			case SCENE_OPTIONS:
			{
				DrawText("OPTIONS", 200, 100, 40, DARKGRAY);
				
				// cesitli ayarlar 
				
				// GuiSlider(Rectangle{ 200, 240, 200, 20 }, "", TextFormat("%2.0f%%", volume * 100), &volume, 0.0f, 1.0f);
				// GuiCheckBox(Rectangle{ 200, 280, 20, 20 }, "Fullscreen", &fullscreen);
				if (GuiButton(Rectangle{ 200, 320, 200, 40 }, "BACK")) 
				{
					currentScene = SCENE_TITLE;
				}
				break;
			}
			break;

			default: break;
		}

		EndDrawing();
	}

	CloseWindow();
}

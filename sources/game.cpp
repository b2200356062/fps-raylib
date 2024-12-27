
#include "game.h"
#include <iostream>
#include <vector>

Game::Game()
{
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
	SetWindowState(FLAG_VSYNC_HINT);
	SetTargetFPS(144);

	ui = new Ui();
	camera = { 0 };
	frameCounter = 0;
}

Game::~Game()
{
	enemies.clear();
	delete ui;
	delete player;
	delete map;
}

void Game::initGameplay()
{
	map = new Map();
	
	player = new Player({ 100.f, 100.f });

	enemies.push_back(new Enemy(1, 100, { 2.f, 1.f, 2.f }));
	enemies.push_back(new Enemy(2, 100, { 5.f, 1.f, 5.f }));
	enemies.push_back(new Enemy(3, 100, { -2.f, 1.f, -2.f }));

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
		// update
		switch (ui->getCurrentScene()) {

			case Ui::TITLE:
			{
				
			}
			break;

			case Ui::GAMEPLAY:
			{
				UpdateCamera(&camera, CAMERA_FIRST_PERSON);

				// UPDATE PLAYER ENEMIES GUN MAP
				map->update();

				for (auto& enemy : enemies) {
					enemy->update();
				}

				player->update(enemies, camera);
				
			}
			break;

			case Ui::OPTIONS:
			{
				// ui.updateOptions();
			}
			break;

			default: break;
		}

		// draw
		BeginDrawing();
		ClearBackground(RAYWHITE);

		switch (ui->getCurrentScene()) 
		{
			case Ui::TITLE:
			{
				ui->drawTitleScreen();
			}
			break;

			case Ui::GAMEPLAY:
			{
				DisableCursor();

				BeginMode3D(camera);

					map->draw();

					for (auto& enemy : enemies) {
						enemy->draw(camera);
					}

				EndMode3D();

				player->draw();

				ui->drawGameplayUI();
			}
			break;

			case Ui::OPTIONS:
			{
				ui->drawOptionsScreen();
			}
			break;

			default: break;
		}

		EndDrawing();
	}

	CloseWindow();
}

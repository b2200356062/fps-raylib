#pragma once
#include "raylib.h"
#include "game.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

#define WINDOW_TITLE "FPS"

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    SetTargetFPS(144);

    Game* game = new Game();
    // Handle Textures
    game->handleTextures();

    while (!WindowShouldClose())
    {
        // Update Game
        game->update();

        BeginDrawing();
        
            ClearBackground(RAYWHITE);
            // Draw Things
            game->draw();

        EndDrawing();
    }


    // Unload All Textures
    // Clear Things
    delete game;
    game = nullptr;

    CloseWindow();

    return 0;
}

#include "ui.h"
#include "raylib.h"
#include "raygui.h"

// Constructor
UI::UI() : selectedOption(0), volume(0.5f), fullscreen(false) {
}

// Destructor
UI::~UI() {
}

// Draw Title Screen
void UI::DrawTitleScreen()
{
    DrawText("RETRO FPS", 200, 100, 40, DARKGRAY);
    if (GuiButton(Rectangle{ 200, 200, 200, 40 }, "OYUNA BAÞLA")) {
        // Start game logic
    }
    if (GuiButton(Rectangle{ 200, 260, 200, 40 }, "AYARLAR")) {
        selectedOption = SCENE_OPTIONS;
    }
    if (GuiButton(Rectangle{ 200, 320, 200, 40 }, "ÇIK")) {
        CloseWindow();
    }
}

// Draw Options Screen
void UI::DrawOptionsScreen()
{
    DrawText("AYARLAR", 200, 100, 40, DARKGRAY);

    // Volume slider
    DrawText("SES", 200, 200, 20, DARKGRAY);
    volume = GuiSlider(Rectangle{ 200, 240, 200, 20 }, "", TextFormat("%2.0f%%", volume * 100), &volume, 0.0f, 1.0f);

    // Fullscreen toggle
    fullscreen = GuiCheckBox(Rectangle{ 200, 280, 20, 20 }, "Fullscreen", &fullscreen);

    if (GuiButton(Rectangle{ 200, 320, 200, 40 }, "Back")) {
        selectedOption = SCENE_TITLE;
    }
}

// Draw Gameplay UI
void UI::DrawGameplayUI()
{
    // Health bar
    DrawText("HEALTH", 20, 20, 20, RED);
    float healthProgress = 0.75f; // Example health value
    GuiProgressBar(Rectangle{ 20, 50, 200, 20 }, NULL, NULL, &healthProgress, 0.0f, 1.0f);

    // Ammo count
    DrawText("AMMO: 30", 20, 80, 20, DARKGRAY);

    // Other gameplay UI elements
}

// Draw Update Screen
void UI::DrawUpdateScreen()
{
    DrawText("UPDATES", 200, 100, 40, DARKGRAY);
    DrawText("Version 1.0", 200, 200, 20, DARKGRAY);
    if (GuiButton(Rectangle{ 200, 320, 200, 40 }, "Back")) {
        selectedOption = SCENE_TITLE;
    }
}

// Update Scene
void UI::UpdateScene(Scene currentScene)
{
    switch (currentScene) {
        case SCENE_TITLE:
            DrawTitleScreen();
            break;
        case SCENE_OPTIONS:
            DrawOptionsScreen();
            break;
        case SCENE_GAMEPLAY:
            DrawGameplayUI();
            break;
        case SCENE_UPDATE:
            DrawUpdateScreen();
            break;
        default:
            break;
    }
}

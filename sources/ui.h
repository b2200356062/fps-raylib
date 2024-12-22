
#pragma once
#include "raylib.h"
#include "raygui.h"


// UI Class
class UI
{
public:
    // Constructor and Destructor
    UI();
    ~UI();

    // Enum for UI Scenes
    enum Scene
    {
        SCENE_TITLE,
        SCENE_OPTIONS,
        SCENE_GAMEPLAY,
        SCENE_UPDATE
    };


    // Methods
    void DrawTitleScreen();
    void DrawOptionsScreen();
    void DrawGameplayUI();
    void DrawUpdateScreen();

    void UpdateScene(Scene currentScene); // Updates the current scene's UI

private:
    // Private variables (e.g., for buttons, sliders)
    int selectedOption;
    float volume;
    bool fullscreen;
};

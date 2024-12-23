//#pragma once
//#include "raylib.h"
//#include "raygui.h"
//
//class UI
//{
//public:
//    UI();
//    ~UI();
//
//    enum Scene
//    {
//        SCENE_TITLE,
//        SCENE_OPTIONS,
//        SCENE_GAMEPLAY,
//        SCENE_UPDATE
//    };
//
//    void Update();               // Update UI logic based on the current scene
//    void Draw();                 // Draw the current scene
//    void SetScene(Scene scene);  // Set the current scene
//    Scene GetScene() const;      // Get the current scene
//
//    bool IsSceneChanged() const; // Check if the scene has changed
//
//private:
//    Scene currentScene;  // The current scene being displayed
//    Scene lastScene;     // The previously displayed scene
//    int selectedOption;  // Holds the selected option (used for transitions)
//    float volume;        // Volume level (0.0f - 1.0f)
//    bool fullscreen;     // Fullscreen toggle
//
//    // Scene-specific methods
//    void DrawTitleScreen();
//    void DrawOptionsScreen();
//    void DrawGameplayUI();
//    void DrawUpdateScreen();
//};

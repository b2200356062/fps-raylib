//#include "ui.h"
//
//// Constructor
//UI::UI() : currentScene(SCENE_TITLE), lastScene(SCENE_TITLE), selectedOption(0), volume(0.5f), fullscreen(false) {}
//
//// Destructor
//UI::~UI() {}
//
//void UI::SetScene(Scene scene)
//{
//    lastScene = currentScene;  // Track the previous scene
//    currentScene = scene;
//}
//
//UI::Scene UI::GetScene() const
//{
//    return currentScene;
//}
//
//bool UI::IsSceneChanged() const
//{
//    return currentScene != lastScene;
//}
//
//void UI::Update()
//{
//    switch (currentScene) {
//        case SCENE_TITLE:
//            if (GuiButton(Rectangle{ 200, 200, 200, 40 }, "OYUNA BAÞLA")) {
//                SetScene(SCENE_GAMEPLAY);
//            }
//            if (GuiButton(Rectangle{ 200, 260, 200, 40 }, "AYARLAR")) {
//                SetScene(SCENE_OPTIONS);
//            }
//            if (GuiButton(Rectangle{ 200, 320, 200, 40 }, "ÇIK")) {
//                CloseWindow();
//            }
//            break;
//
//        case SCENE_OPTIONS:
//            volume = GuiSlider(Rectangle{ 200, 240, 200, 20 }, "", TextFormat("%2.0f%%", volume * 100), &volume, 0.0f, 1.0f);
//            fullscreen = GuiCheckBox(Rectangle{ 200, 280, 20, 20 }, "Fullscreen", &fullscreen);
//            if (GuiButton(Rectangle{ 200, 320, 200, 40 }, "Back")) {
//                SetScene(SCENE_TITLE);
//            }
//            break;
//
//        default:
//            break;
//    }
//}
//
//void UI::Draw()
//{
//    switch (currentScene) {
//        case SCENE_TITLE:
//            DrawTitleScreen();
//            break;
//        case SCENE_OPTIONS:
//            DrawOptionsScreen();
//            break;
//        case SCENE_GAMEPLAY:
//            DrawGameplayUI();
//            break;
//        case SCENE_UPDATE:
//            DrawUpdateScreen();
//            break;
//        default:
//            break;
//    }
//}
//
//// Private draw methods
//void UI::DrawTitleScreen()
//{
//    DrawText("RETRO FPS", 200, 100, 40, DARKGRAY);
//}
//
//void UI::DrawOptionsScreen()
//{
//    DrawText("AYARLAR", 200, 100, 40, DARKGRAY);
//}
//
//void UI::DrawGameplayUI()
//{
//    DrawText("HEALTH", 20, 20, 20, RED);
//}
//
//void UI::DrawUpdateScreen()
//{
//    DrawText("UPDATES", 200, 100, 40, DARKGRAY);
//}

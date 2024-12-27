
#include "ui.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include <iostream>

Ui::Ui()
{
	font = LoadFont(ASSETS_PATH"fonts/rodin.otf");
	currentScene = TITLE;
}

Ui::~Ui()
{
	UnloadFont(font);
}

void Ui::drawText(const char* text, Vector2 position, float fontSize, float spacing, Color tint)
{
	Vector2 length = MeasureTextEx(font, text, fontSize * font.baseSize, spacing);
	Vector2 dividedLength = Vector2Divide(length, Vector2{ 2.f, 2.f });
	Vector2 newPosition = Vector2Subtract(position, dividedLength);
	
	DrawTextEx(font, text, newPosition, fontSize * font.baseSize, spacing, tint);
}

void Ui::drawTitleScreen()
{
    drawText("RETRO FPS", Vector2{ static_cast<float>(GetScreenWidth()) / 2, static_cast<float>(GetScreenHeight()) / 8}, 2, 1, BLACK);
	// drawText("RETRO FPS", Vector2{ GetScreenWidth() / 2, GetScreenHeight() / 8 }, 2, 1, BLACK);

	if (GuiButton(Rectangle{ static_cast<float>(GetScreenWidth()) / 2 - 100,  static_cast<float>(GetScreenHeight()) / 2, 200, 40 }, "START"))
	{
		updateScene(GAMEPLAY);
	}
	if (GuiButton(Rectangle{ static_cast<float>(GetScreenWidth()) / 2 - 100,  static_cast<float>(GetScreenHeight()) / 2 + 50, 200, 40 }, "OPTIONS"))
	{
		updateScene(OPTIONS);
	}
	if (GuiButton(Rectangle{ static_cast<float>(GetScreenWidth()) / 2 - 100,  static_cast<float>(GetScreenHeight()) / 2 + 100, 200, 40 }, "EXIT"))
	{
		exit(0);
	}
}

void Ui::drawOptionsScreen()
{
	drawText("Ayarlar", Vector2{ static_cast<float>(GetScreenWidth()) / 2, static_cast<float>(GetScreenHeight()) / 8 }, 2, 1, BLACK);


	// GuiSlider(Rectangle{ 200, 240, 200, 20 }, "", TextFormat("%2.0f%%", volume * 100), &volume, 0.0f, 1.0f);
	//GuiCheckBox(Rectangle{ 200, 280, 20, 20 }, "Fullscreen", &fullscreen);

	if (GuiButton(Rectangle{ 200, 320, 200, 40 }, "BACK"))
	{
		updateScene(TITLE);
	}
	
}

void Ui::drawGameplayUI()
{
	float health = GuiSlider(Rectangle{ 50, 550, 30, 10 }, "CAN", "", &health, 0, 100);
}

Vector2 Ui::center(Vector2 position)
{
	return Vector2();
}

void Ui::updateScene(Scene scene)
{
	currentScene = scene;
}

Ui::Scene Ui::getCurrentScene() const
{
	return currentScene;
}





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

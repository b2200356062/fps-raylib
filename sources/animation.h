#pragma once
#include "raylib.h"

class Animation
{
private:
    std::vector<Texture2D> frames;   // Ayr� PNG dosyalar� i�in
    std::vector<Rectangle> spriteFrames; // Sprite sheet �er�eveleri i�in
    Texture2D spriteSheet;          // Sprite sheet dosyas�
    float frameTime;                // Her bir �er�evenin s�resi
    float timer;                    // Zamanlay�c�
    int currentFrame;               // Ge�erli �er�eve
    bool useSpriteSheet;            // Sprite sheet mi kullan�l�yor?

public:
    // Constructor (Sprite Sheet i�in)
    Animation(Texture2D sheet, std::vector<Rectangle> frameRects, float frameDuration);

    // Constructor (Ayr� PNG dosyalar� i�in)
    Animation(std::vector<std::string> framePaths, float frameDuration);

    // Destructor
    ~Animation();

    // Animasyon zamanlamas� g�ncelle
    void Update(float deltaTime);

    // Animasyonu ekrana �izdir
    void Draw(Vector2 position);
};

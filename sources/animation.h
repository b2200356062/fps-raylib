#pragma once
#include "raylib.h"

class Animation
{
private:
    std::vector<Texture2D> frames;   // Ayrý PNG dosyalarý için
    std::vector<Rectangle> spriteFrames; // Sprite sheet çerçeveleri için
    Texture2D spriteSheet;          // Sprite sheet dosyasý
    float frameTime;                // Her bir çerçevenin süresi
    float timer;                    // Zamanlayýcý
    int currentFrame;               // Geçerli çerçeve
    bool useSpriteSheet;            // Sprite sheet mi kullanýlýyor?

public:
    // Constructor (Sprite Sheet için)
    Animation(Texture2D sheet, std::vector<Rectangle> frameRects, float frameDuration);

    // Constructor (Ayrý PNG dosyalarý için)
    Animation(std::vector<std::string> framePaths, float frameDuration);

    // Destructor
    ~Animation();

    // Animasyon zamanlamasý güncelle
    void Update(float deltaTime);

    // Animasyonu ekrana çizdir
    void Draw(Vector2 position);
};

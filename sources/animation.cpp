#include "animation.h"

#include <vector>
#include <string>

// Constructor (Sprite Sheet için)
Animation::Animation(Texture2D sheet, std::vector<Rectangle> frameRects, float frameDuration)
    : spriteSheet(sheet), spriteFrames(frameRects), frameTime(frameDuration), timer(0), currentFrame(0), useSpriteSheet(true)
{
}

// Constructor (Ayrý PNG dosyalarý için)
Animation::Animation(std::vector<std::string> framePaths, float frameDuration)
    : frameTime(frameDuration), timer(0), currentFrame(0), useSpriteSheet(false)
{
    for (const auto& path : framePaths) {
        frames.push_back(LoadTexture(path.c_str()));
    }
}

// Destructor
Animation::~Animation()
{
    if (!useSpriteSheet) {
        for (auto& frame : frames) {
            UnloadTexture(frame);
        }
    }
}

// Animasyon güncelleme
void Animation::Update(float deltaTime)
{
    timer += deltaTime;
    if (timer >= frameTime) {
        timer = 0;
        currentFrame = (currentFrame + 1) % (useSpriteSheet ? spriteFrames.size() : frames.size());
    }
}

// Animasyonu çizdirme
void Animation::Draw(Vector2 position)
{
    if (useSpriteSheet) {
        Rectangle sourceRect = spriteFrames[currentFrame];
        Rectangle destRect = { position.x, position.y, sourceRect.width, sourceRect.height };
        DrawTexturePro(spriteSheet, sourceRect, destRect, { 0, 0 }, 0.0f, WHITE);
    }
    else {
        DrawTexture(frames[currentFrame], position.x, position.y, WHITE);
    }
}

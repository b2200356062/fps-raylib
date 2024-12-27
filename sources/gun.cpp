#include "gun.h"
#include <iostream>

Gun::Gun()
{
	ammoRemaining = 120;
	gunSprite = LoadTexture(ASSETS_PATH"textures/guns/mcgun.png");
	frameWidth = gunSprite.width / 4; // Çerçeve geniþliði (örneðin, 4 çerçeve varsa)
	frameHeight = gunSprite.height;
	frameCount = 4; // Çerçeve sayýsý
	frameTime = 0.1f;
	currentFrame = 0;
	timer = 0.0f;
	isShooting = false;
	isReloading = false;
}

Gun::~Gun()
{
	UnloadTexture(gunSprite);
}

void Gun::update()
{
	if (!isShooting) return;

	timer += GetFrameTime();
	if (timer >= frameTime)
	{
		timer = 0.0f;
		currentFrame++;

		if (currentFrame >= frameCount)
		{
			currentFrame = 0; // Animasyonu sýfýrla
			isShooting = false; // Ateþ etmeyi durdur
		}
	}
}

void Gun::draw() const
{
	int row = currentFrame / 4;
	int col = currentFrame % 4;
	Rectangle sourceRect = { col * frameWidth, row * frameHeight, frameWidth, frameHeight };
	Rectangle destRect = { GetScreenWidth() / 2 - (frameWidth / 2), GetScreenHeight() - frameHeight, frameWidth, frameHeight};
	DrawTexturePro(gunSprite, sourceRect, destRect, { 0, 0 }, 0.0f, WHITE);
}

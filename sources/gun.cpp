#include "gun.h"
#include <iostream>

Gun::Gun()
{
	ammoRemaining = 120;
	gunSprite = LoadTexture(ASSETS_PATH"textures/guns/mcgun.png");
	frameWidth = gunSprite.width / 4; 
	frameHeight = gunSprite.height;
	frameCount = 4;
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
			currentFrame = 0;
			isShooting = false;
		}
	}
}

void Gun::draw() const
{
	int row = currentFrame / 4;
	int col = currentFrame % 4;
	Rectangle sourceRect = { col * frameWidth, row * frameHeight, frameWidth, frameHeight };
	Rectangle destRect = { GetScreenWidth() / 2 - (frameWidth / 2) - 68, GetScreenHeight() - frameHeight, frameWidth, frameHeight};
	DrawTexturePro(gunSprite, sourceRect, destRect, { 0, 0 }, 0.0f, WHITE);
}

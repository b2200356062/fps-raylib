#include "gun.h"

Gun::Gun()
{
	ammoRemaining = 0;
	gunSprite = LoadTexture(ASSETS_PATH"textures/guns/mcgun.png");
	frameWidth = gunSprite.width / 4; // Çerçeve geniþliði (örneðin, 4 çerçeve varsa)
	frameHeight = gunSprite.height;
	frameCount = 4; // Çerçeve sayýsý
	frameTime = 0.7f;
	currentFrame = 0;
	timer = 0.0f;
	isShooting = false;
	isReloading = false;

}

Gun::~Gun()
{

}

void Gun::update()
{
	timer += GetFrameTime();
	if (timer >= frameTime) {
		timer = 0.0f;
		currentFrame++;
		if (isShooting && currentFrame >= 5) {
			currentFrame = 0;
			isShooting = false;
		}
		if (isReloading && currentFrame >= frameCount) {
			currentFrame = 5;
			isReloading = false;
		}
	}
}

void Gun::shoot()
{
	isShooting = true;
	isReloading = false;
	currentFrame = 0;
}

void Gun::reload()
{
	isShooting = false;
	isReloading = true;
	currentFrame = 5;
}

void Gun::draw() const
{
	int row = currentFrame / 4;
	int col = currentFrame % 4;
	Rectangle sourceRect = { col * frameWidth, row * frameHeight, frameWidth, frameHeight };
	Rectangle destRect = { 400 - frameWidth / 2, 225 - frameHeight / 2, frameWidth, frameHeight };
	DrawTexturePro(gunSprite, sourceRect, destRect, { 0, 0 }, 0.0f, WHITE);
}

void Gun::clear() const
{
	UnloadTexture(gunSprite);
}

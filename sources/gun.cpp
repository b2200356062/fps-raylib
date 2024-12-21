#include "gun.h"
#include "iostream"

Gun::Gun()
{
	ammoRemaining = 90;
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
	//UnloadTexture(gunSprite);
}

void Gun::update()
{
	if (isShooting) {
		timer += GetFrameTime();
		if (timer >= frameTime) {
			timer = 0.0f;
			currentFrame++;
			if (currentFrame >= frameCount) {
				currentFrame = 0;
				isShooting = false;
			}
		}
	}
}

void Gun::shoot()
{
	if (ammoRemaining == 0) {
		DrawText("NO AMMO LEFT", GetScreenWidth() / 2 - 50, GetScreenHeight() / 2 + 100, 30, BLACK);
	}

	if (!isShooting && ammoRemaining > 0) {
		isShooting = true;
		ammoRemaining--;
		isReloading = false;
		currentFrame = 0;
		timer = 0.0f;
	}
	
	std::cout << ammoRemaining << "\n";
}

void Gun::reload()
{
	isShooting = false;
	isReloading = true;
	currentFrame = 0;
}

void Gun::draw() const
{
	int row = currentFrame / 4;
	int col = currentFrame % 4;
	Rectangle sourceRect = { col * frameWidth, row * frameHeight, frameWidth, frameHeight };
	Rectangle destRect = { 400 - frameWidth / 2, 225 - frameHeight / 2, frameWidth, frameHeight };
	DrawTexturePro(gunSprite, sourceRect, destRect, { 0, 0 }, 0.0f, WHITE);
}

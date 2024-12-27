#include "player.h"

#include <iostream>

Player::Player(Vector3 position)
{
	this->position = position;
	health = 100;
	speed = 25;
	gun = new Gun();
	shootCooldown = 0.2f; 
	timeSinceLastShot = 0.0f;
}


Player::~Player()
{
	delete gun;
}

void Player::update(std::vector<Enemy*>& enemies, Camera3D& camera)
{
	float deltaTime = GetFrameTime();
	timeSinceLastShot += deltaTime;

	if (IsKeyDown(KEY_W)) position.z -= speed * deltaTime;
	if (IsKeyDown(KEY_S)) position.z += speed * deltaTime;
	if (IsKeyDown(KEY_A)) position.x -= speed * deltaTime;
	if (IsKeyDown(KEY_D)) position.x += speed * deltaTime;

	// Ateþ etme kontrolü
	if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && timeSinceLastShot >= shootCooldown)
	{
		shoot(enemies, camera); // Ateþ et
		timeSinceLastShot = 0.0f; // Zamanlayýcýyý sýfýrla
	}

	if (!IsMouseButtonDown(MOUSE_BUTTON_LEFT))
	{
		gun->isShooting = false; // Ateþi durdur
	}

	gun->update(); // Silah animasyonunu güncelle

	if (IsKeyDown(KEY_R))
	{
		gun->isShooting = false;
		gun->currentFrame = 0;
		gun->timer = 0.0f;
	}
}

void Player::shoot(std::vector<Enemy*>& enemies, Camera3D& camera)
{
	gun->isShooting = true; // Silahýn ateþ ettiðini iþaretle

	Vector2 screenCenter = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };
	Ray ray = GetMouseRay(screenCenter, camera);

	for (auto& enemy : enemies)
	{
		if (GetRayCollisionBox(ray, enemy->getBoundingBox()).hit)
		{
			std::cout << "enemy hit: " << enemy->getHealth() << "\n";
			enemy->getHit(20); 
			
			break;
		}
	}
}


void Player::draw()
{
	gun->draw();
	// draw crosshair
	Vector2 screenCenter = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };
	DrawLine(screenCenter.x - 10, screenCenter.y, screenCenter.x + 10, screenCenter.y, GREEN);
	DrawLine(screenCenter.x, screenCenter.y - 10, screenCenter.x, screenCenter.y + 10, GREEN);
}

void Player::reload()
{

}



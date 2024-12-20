#include "player.h"

Player::Player()
{
	health = 100;
	position = { 100.f, 100.f };
	speed = 5;
	gun = new Gun();
}

Player::~Player()
{
}

Player::Player(Vector2 position)
{
	this->position = position;
	health = 100;
	speed = 25;
	gun = new Gun();
}

void Player::update()
{
	if (IsKeyDown(KEY_W)) position.y -= speed;
	if (IsKeyDown(KEY_S)) position.y += speed;
	if (IsKeyDown(KEY_A)) position.x -= speed;
	if (IsKeyDown(KEY_D)) position.x += speed;

	if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
		gun->shoot();
	}

	if (IsKeyDown(KEY_R)) {
		gun->reload();
	}

	gun->update();
}

void Player::drawGun()
{
	gun->draw();
}

void Player::draw()
{
	drawGun();
}

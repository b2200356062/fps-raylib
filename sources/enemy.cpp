#include "enemy.h"
#include <iostream>

Enemy::Enemy()
{

}

Enemy::Enemy(int type, int health, Vector3 position, const char* texturePath)
{
	this->type = type;
	this->health = health;
	this->position = position;
	this->texture = LoadTexture(texturePath);

	// Adjust the size of the bounding box 
	float boundingBoxWidth = 0.3f;  // Adjust width as needed
	float boundingBoxHeight = 0.7f; // Adjust height as needed
	float boundingBoxDepth = 0.5f;  // Adjust depth as needed

	this->boundingBox = {
		Vector3Subtract(position, Vector3{boundingBoxWidth, boundingBoxHeight, boundingBoxDepth}),
		Vector3Add(position, Vector3{boundingBoxWidth, boundingBoxHeight, boundingBoxDepth})
	};

}

Enemy::~Enemy()
{
	UnloadTexture(texture);
}

void Enemy::update()
{
	
}

void Enemy::draw(Camera3D camera)
{
	DrawBillboard(camera, texture, position, 1.5f, WHITE);
	DrawBoundingBox(boundingBox, RED);
}

void Enemy::getHit(int damage)
{
	// play enemy hit animation;

	if (health <= 0) {
		return;
	}

	health -= damage;
	std::cout << "enemy health:" << getHealth() << "\n";
	if (health <= 0) {
		die();
	}
}

void Enemy::die()
{
	// play death animation
	std::cout << "enemy died" << "\n";
}

int Enemy::getHealth() const
{
	return health;
}

Vector3 Enemy::getPosition() const
{
	return position;
}

BoundingBox Enemy::getBoundingBox() const
{
	return boundingBox;
}

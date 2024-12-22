#include "enemy.h"
#include "raymath.h"

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
	health -= damage;
	if (health <= 0) {
		die();
	}
}

void Enemy::die()
{

}

Vector3 Enemy::getPosition() const
{
	return position;
}

BoundingBox Enemy::getBoundingBox() const
{
	return boundingBox;
}

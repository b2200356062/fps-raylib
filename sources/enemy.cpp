#include "enemy.h"

Enemy::Enemy()
{

}

Enemy::Enemy(int type, int health, Vector2 position)
{
	this->type = 0;
	this->health = health;
	this->position = position;
}

Enemy::~Enemy()
{
}

void Enemy::update()
{
}

void Enemy::draw()
{
}

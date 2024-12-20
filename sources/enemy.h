#pragma once
#include "raylib.h"

class Enemy
{
private:
	int type;
	int health;
	Vector2 position;

public:

	Enemy();
	Enemy(int type, int health,  Vector2 position);
	
	~Enemy();
	void update();
	void draw();

};
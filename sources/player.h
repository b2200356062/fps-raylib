#pragma once
#include "raylib.h"
#include "gun.h"
#include <iostream>

class Player
{
private:

	int health;
	Vector2 position;
	float speed;
	Gun *gun;

public:

	Player();
	~Player();

	Player(Vector2 position);
	
	void update();
	void draw();
	void drawGun();
};
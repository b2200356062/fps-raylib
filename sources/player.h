#pragma once
#include "raylib.h"
#include "gun.h"
#include <iostream>

class Player
{
private:

	int health;
	Vector3 position;
	float speed;
	Gun *gun;

public:

	Player();
	~Player();

	Player(Vector3 position);
	
	void update();
	void draw();
	void drawGun();
};
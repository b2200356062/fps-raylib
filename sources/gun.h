#pragma once
#include "raylib.h"

class Gun
{
public:
	Gun();
	~Gun();

	void update();
	void draw() const;

private:
	int ammoRemaining;
	int frameWidth;
	int frameHeight;
	int frameCount;
	int frameTime;
	int currentFrame;
	float timer;
	bool isShooting;
	bool isReloading;
	Texture2D gunSprite;

	friend class Player; // Allow Player class to access private members
};
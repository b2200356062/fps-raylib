#pragma once
#include "raylib.h"

class Gun
{
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

public:
	
	Gun();
	~Gun();
	
	void update();
	void shoot();
	void reload();
	void draw() const;

};
#pragma once
#include "raylib.h"

class Enemy
{
public:
	Enemy();
	Enemy(int type, int health, Vector3 position, const char* texturePath);

	~Enemy();

	void update();
	void draw(Camera3D camera);
	void getHit(int damage);
	void die();

	Vector3 getPosition() const;
	BoundingBox getBoundingBox() const;


private:
	int type;
	int health;
	Vector3 position;
	Texture2D texture;
	BoundingBox boundingBox;
};
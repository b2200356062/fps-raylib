#pragma once
#include "raylib.h"
#include "gun.h"

class Game
{
private:

public:
	Game();
	~Game();

	void handleTextures();
	void update();
	void draw();
	void clear();

};
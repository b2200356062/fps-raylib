#pragma once
#include "raylib.h"
#include "pickables.h"
#include <vector>

class Map
{
public:

	std::vector<Pickup*> pickups;

	Map();
	~Map();

	void addPickup(Vector3 position, PickupType type);
	void update();
	void draw();

};
#include "map.h"
#include <iostream>

Map::Map()
{
	std::cout << "map olustu! \n";
}

Map::~Map()
{
	
}

void Map::addPickup(Vector3 position, PickupType type)
{
}

void Map::update()
{
}

void Map::draw()
{

	DrawPlane(Vector3{ 0.0f, 0.0f, 0.0f }, Vector2{ 25, 25 }, GRAY);
	DrawCube(Vector3{ 0.0f, 5.f, 25.f }, 0.5f, 15, 10, DARKBROWN);
}



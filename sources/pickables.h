#pragma once
#include "raylib.h"

enum class PickupType{
	Health, Armor, Ammo
};

class Pickup
{
public:
    Vector3 position;  
    PickupType type;   
    float radius;
    bool isActive;

    Pickup(Vector3 pos, PickupType type, Texture2D texture);
    void draw(Camera3D camera);

private:
 
    Texture2D texture;
    //Vector3 position;
};
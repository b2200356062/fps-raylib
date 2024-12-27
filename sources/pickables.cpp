#include "pickables.h"
#include <iostream>

Pickup::Pickup(Vector3 pos, PickupType type, Texture2D texture)
    : position(pos), type(type), radius(1.0f), isActive(true)
{
    if (type == PickupType::Health) 
    {
        texture = LoadTexture(ASSETS_PATH"textures/pickables/health-red.png");
    }
    else if (type == PickupType::Armor) 
    {
        texture = LoadTexture(ASSETS_PATH"textures/pickables/ammo-rifle.png");
    }
    else {
        texture = LoadTexture(ASSETS_PATH"textures/pickables/armor.png");
    }

}

void Pickup::draw(Camera3D camera)
{
    if (!isActive) return;

    DrawBillboard(camera, texture, position, 1, WHITE);
}
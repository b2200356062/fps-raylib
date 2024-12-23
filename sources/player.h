#pragma once

#include "raylib.h"
#include "gun.h"
#include "enemy.h"
#include <vector>

class Player
{
public:
    Player(Vector3 position);
    ~Player();

    void update(std::vector<Enemy*>& enemies, Camera3D& camera);
    void draw();
    void reload();
    void shoot(std::vector<Enemy*>& enemies, Camera3D& camera);

private:
    Gun* gun;
    int health;
    float speed;
    Vector3 position;
    
    float shootCooldown; // Cooldown period between shots
    float timeSinceLastShot; // Time since the last shot was fired
};
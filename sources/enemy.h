#pragma once
#include "raylib.h"
#include "raymath.h"
#include "Animation.h"
#include <vector>
#include <string>
#include <memory> // For smart pointers

class Enemy
{
public:
    Enemy();
    Enemy(int type, int health, Vector3 position);
    ~Enemy();

    void update(float deltaTime);
    void draw(Camera3D camera);
    void getHit(int damage);
    void die();

    int getHealth() const;
    Vector3 getPosition() const;
    BoundingBox getBoundingBox() const;

private:
    int type;
    int health;
    Vector3 position;

    BoundingBox boundingBox;

    // Animasyonlar
    std::unique_ptr<Animation> idleAnimation;
    std::unique_ptr<Animation> walkingAnimation;
    std::unique_ptr<Animation> deathAnimation;
    std::unique_ptr<Animation> hurtAnimation;

    Animation* currentAnimation; // Aktif animasyon
};

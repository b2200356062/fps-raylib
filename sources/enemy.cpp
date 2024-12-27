#include "Enemy.h"

// Default Constructor
Enemy::Enemy() : type(0), health(100), position({0, 0, 0}), currentAnimation(nullptr) {}

// Parametreli Constructor
Enemy::Enemy(int type, int health, Vector3 position)
    : type(type), health(health), position(position), currentAnimation(nullptr) {
    // Bounding box olu�tur
    boundingBox = {
        {position.x - 0.5f, position.y, position.z - 0.5f},
        {position.x + 0.5f, position.y + 1.0f, position.z + 0.5f}
    };

    // Animasyonlar� y�kle
    idleAnimation = std::make_unique<Animation>(
        std::vector<std::string>{"enemy_idle1.png", "enemy_idle2.png", "enemy_idle3.png"}, 0.2f);
    walkingAnimation = std::make_unique<Animation>(
        std::vector<std::string>{"enemy_walk1.png", "enemy_walk2.png", "enemy_walk3.png"}, 0.15f);
    deathAnimation = std::make_unique<Animation>(
        std::vector<std::string>{"enemy_death1.png", "enemy_death2.png", "enemy_death3.png"}, 0.25f);
    hurtAnimation = std::make_unique<Animation>(
        std::vector<std::string>{"enemy_hurt1.png", "enemy_hurt2.png"}, 0.1f);

    // Varsay�lan animasyon
    currentAnimation = idleAnimation.get();
}

// Destructor
Enemy::~Enemy() {}

// Update
void Enemy::update(float deltaTime) {
    if (currentAnimation) {
        currentAnimation->Update(deltaTime);
    }

    // Hareket veya sald�r� durumuna g�re animasyon de�i�tir (�rnek)
    if (health <= 0) {
        currentAnimation = deathAnimation.get();
    }
}

// Draw
void Enemy::draw(Camera3D camera) {
    if (currentAnimation) {
        Vector3 screenPos = GetWorldToScreen(position, camera);
        currentAnimation->Draw({screenPos.x - 16, screenPos.y - 16}); // Ekran koordinatlar�na g�re �izim
    }
}

// Hasar alma
void Enemy::getHit(int damage) {
    health -= damage;

    if (health > 0) {
        currentAnimation = hurtAnimation.get();
    } else {
        die();
    }
}

// �l�m
void Enemy::die() {
    currentAnimation = deathAnimation.get();
    // Di�er �l�m i�lemleri
}

// Sa�l�k de�erini d�nd�r
int Enemy::getHealth() const {
    return health;
}

// Pozisyonu d�nd�r
Vector3 Enemy::getPosition() const {
    return position;
}

// BoundingBox d�nd�r
BoundingBox Enemy::getBoundingBox() const {
    return boundingBox;
}

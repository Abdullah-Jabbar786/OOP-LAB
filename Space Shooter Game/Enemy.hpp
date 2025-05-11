#pragma once
#include "raylib.h"

class Enemy
{
protected:
    Vector2 position;
    float speed;
    Texture2D img;
    bool active;
    int health;

public:
    Enemy(float x, float y); 
    virtual void Update();  
    virtual void Draw() const;
    Rectangle GetRect();  
    void Deactivate();
    bool IsActive() const;
    void TakeDamage(int damage);  // Damage from bullets

    virtual int GetDamageOnCollision() const = 0;  // Abstract function to get damage on collision wih any enemy.
    virtual int GetScoreValue() const = 0;

    virtual ~Enemy();
};

// Level 1 Enemy
class EnemyLevel1 : public Enemy
{
public:
    EnemyLevel1(float x, float y);
    void Update() override;
    int GetDamageOnCollision() const override {return 10;}
    int GetScoreValue() const override {return 10;}
};

// Level 2 Enemy
class EnemyLevel2 : public Enemy
{
public:
    EnemyLevel2(float x, float y);
    void Update() override;
    int GetDamageOnCollision() const override {return 20;}
    int GetScoreValue() const override {return 20;}
};

// Level 3 Enemy
class EnemyLevel3 : public Enemy
{
public:
    EnemyLevel3(float x, float y);
    void Update() override;
    int GetDamageOnCollision() const override {return 30;}
    int GetScoreValue() const override {return 30;}
};

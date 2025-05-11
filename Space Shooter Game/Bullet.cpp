#include "Bullet.hpp"
#include "iostream"

using namespace std;

    Bullet::Bullet(Vector2 position, float speed)
    {
        b = LoadTexture("Graphics/bullet.png");
        this->position = position;
        this->speed = speed;
        active = true;
    }
    
    void Bullet::Drawb()
    {
        if (active)
        {
            DrawTextureV(b,position,WHITE);
        }
    }

    void Bullet::Updateb()
    {
        position.y += speed;
        if (active)
        {
            //Is bullet out of the screen?
            if (position.y > GetScreenHeight() || position.y < 0)
            {
                active = false;
            }
        }
    } 

    Rectangle Bullet::GetRect()
    {
        Rectangle rect;
        rect.x = position.x;
        rect.y = position.y;
        rect.width = 4;
        rect.height = 15;
        return rect;
    }

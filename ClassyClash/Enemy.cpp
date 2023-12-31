#include "raylib.h"
#include "raymath.h"
#include "Enemy.h"
#include "BaseCharacter.h"



Enemy :: Enemy(Vector2 pos, Texture2D idle_texture, Texture2D run_texture)   
{
    worldPos = pos;
    texture = idle_texture;
    idle = idle_texture;
    run = run_texture;    

    width = texture.width / maxFrame;
    height = texture.height;
    speed = 3.f;
}


Vector2 Enemy :: GetScreenPos()
{
    return Vector2 { Vector2Subtract(worldPos, target->getWorldPos()) };
}

void Enemy::tick(float deltaTime)
{
   
  
    Velocity = Vector2Subtract(target->GetScreenPos(), GetScreenPos());

    // set world pos for enemy erach freame -> worldPos += toTarget
    
    //BaseCharacter :: tick(deltaTime);    


}

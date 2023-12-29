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
}


void Enemy::tick(float deltaTime)
{
    BaseCharacter :: tick(deltaTime);
}
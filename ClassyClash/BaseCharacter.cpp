#include "raylib.h"
#include "raymath.h"
#include "BaseCharacter.h"

BaseCharacter :: BaseCharacter ()
{

}

void BaseCharacter :: undoMovement()
{
    worldPos = worldPosLastFrame;
}

Rectangle BaseCharacter :: get_collision_rec()
{
    return Rectangle{
                GetScreenPos().x,
                GetScreenPos().y,
                texture.width * scale / maxFrame,
                texture.height*scale
    };
}

void BaseCharacter::tick(float deltaTime)
{
    worldPosLastFrame = worldPos;
    
    // Update animation data
    runningTime += deltaTime;
    if (runningTime >= updateTime)
    {
        frame++;
        runningTime = 0.f;

        if (frame > maxFrame)
            frame = 0;
    }


    if (Vector2Length(Velocity) != 0.0)
    {
        // Set worldPos = worldPos + Velocity
        worldPos = Vector2Add(worldPos, Vector2Scale(Vector2Normalize(Velocity), speed));

        // Ternary operator setting up our facing Velocity based on movement Velocity
        Velocity.x < 0.f ? rightLeft = -1.f : rightLeft = 1.f;
        texture = run;
    }
    else
    {
        texture = idle;
    }

    Velocity = {};

    // Draw sprite
    Rectangle Source{width* frame, 0.f, rightLeft * width, height};
    Rectangle Dest{GetScreenPos().x, GetScreenPos().y, scale * width, scale * height};
    Vector2 origin{};
    DrawTexturePro(texture, Source, Dest, origin, 0.f, WHITE);

}
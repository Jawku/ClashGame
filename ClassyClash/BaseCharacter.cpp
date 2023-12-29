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
                screenPos.x,
                screenPos.y,
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

    // Draw sprite
    Rectangle Source{width* frame, 0.f, rightLeft * width, height};
    Rectangle Dest{screenPos.x, screenPos.y, scale * width, scale * height};
    Vector2 origin{};
    DrawTexturePro(texture, Source, Dest, origin, 0.f, WHITE);

}
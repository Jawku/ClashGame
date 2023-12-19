#include "character.h"
#include "raylib.h"
#include "raymath.h"


character :: character()
{
    width = texture.width / maxFrame;
    height = texture.height;
}


void character::setScreenPos(int winWidth, int winHeight)
{
    screenPos = {
        (float)winWidth / 2.0f - 4.0f * (0.5f * width),
        (float)winHeight / 2.0f - 4.0f * (0.5f * height)};
}

void character::tick(float deltaTime)
{
    // Player input definition:
    Vector2 Direction{};
    if (IsKeyDown(KEY_A))
        Direction.x -= 1.0;
    if (IsKeyDown(KEY_D))
        Direction.x += 1.0;
    if (IsKeyDown(KEY_S))
        Direction.y += 1.0;
    if (IsKeyDown(KEY_W))
        Direction.y -= 1.0;

    if (Vector2Length(Direction) != 0.0)
    {
        // Set worldPos = worldPos + direction
        worldPos = Vector2Add(worldPos, Vector2Scale(Vector2Normalize(Direction), speed));

        // Ternary operator setting up our facing direction based on movement direction
        Direction.x < 0.f ? rightLeft = -1.f : rightLeft = 1.f;
        texture = run;
    }
    else
    {
        texture = idle;
    }

    // Update animation data
    runningTime += deltaTime;
    if (runningTime >= updateTime)
    {
        frame++;
        runningTime = 0.f;

        if (frame > maxFrame)
            frame = 0;
    }

    // Draw Knight
    Rectangle Source{width* frame, 0.f, rightLeft * width, height};
    Rectangle Dest{screenPos.x, screenPos.y, 4.0f * width, 4.0f * height};
    Vector2 origin{};
    DrawTexturePro(texture, Source, Dest, origin, 0.f, WHITE);
}


#include <cstdio>
#include "raylib.h"
#include "raymath.h"

class character
{
public:
    Vector2 getWorldPos() { return worldPos; }
    void setScreenPos(int winWidth, int winHeight);
    void tick(float deltaTime);

private:
    Texture2D texture{LoadTexture("Textures/characters/knight_idle_spritesheet.png")};
    Texture2D idle{LoadTexture("Textures/characters/knight_idle_spritesheet.png")};
    Texture2D run{LoadTexture("Textures/characters/knight_run_spritesheet.png")};
    Vector2 screenPos{};
    Vector2 worldPos{};

    // 1: facing right, -1 facing left
    float rightLeft{1};
    // animation variables
    const int maxFrame{6};
    int frame{0};
    const float updateTime{1.f / 12.f};
    float runningTime{};

    const float speed{4.f};
};

void character::setScreenPos(int winWidth, int winHeight)
{
    screenPos = {
        (float)winWidth / 2.0f - 4.0f * (0.5f * (float)texture.width / 6.0f),
        (float)winHeight / 2.0f - 4.0f * (0.5f * (float)texture.height)};
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
    Rectangle Source{(float)texture.width / 6.f * frame, 0.f, rightLeft * (float)texture.width / 6.f, (float)texture.height};
    Rectangle Dest{screenPos.x, screenPos.y, 4.0f * (float)texture.width / 6.f, 4.0f * (float)texture.height};
    Vector2 origin{};
    DrawTexturePro(texture, Source, Dest, origin, 0.f, WHITE);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    const int WindowDimension[2]{768, 768};

    InitWindow(WindowDimension[0], WindowDimension[1], "Clash Of Titi");

    // Loading map:
    Texture2D Map = LoadTexture("Textures/FirstMap.png");
    Vector2 MapPos{0.0, 0.0};

    // Initialization of our character class variable:
    character knight;
    // setting up screenPos -> where in window we will draw our character
    knight.setScreenPos(WindowDimension[0],WindowDimension[1]);
    
    SetTargetFPS(120);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        // We need to move our map in opposit direction of our WorldPos
        // World pos - vector that defines where we want to move our character.        
        MapPos = Vector2Scale(knight.getWorldPos(),-1.f);

        // Draw the map
        DrawTextureEx(Map, MapPos, 0, 4, WHITE);

        // Doing evrything that has to be done each frame in our character class with usage of tick function
        knight.tick(GetFrameTime());

        EndDrawing();
    }

    CloseWindow();
}
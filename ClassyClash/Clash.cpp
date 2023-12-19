#include <cstdio>
#include "raylib.h"
#include "raymath.h"
#include "character.h"


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
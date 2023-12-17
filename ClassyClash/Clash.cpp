#include <cstdio>
#include "raylib.h"
#include "raymath.h"



int main()
{
    const int WindowDimension[2]{768, 768};

InitWindow(WindowDimension[0],WindowDimension[1],"Clash Of Titi");


// Loading map:
Texture2D Map = LoadTexture("Textures/FirstMap.png");
Vector2 MapPos{0.0,0.0};
float Speed = 4.0;

// Load character:
Texture2D KnightRun = LoadTexture("Textures/characters/knight_run_spritesheet.png");
Texture2D Knight = LoadTexture("Textures/characters/knight_idle_spritesheet.png");
Vector2 KnightPos{
    (float)WindowDimension[0]/2.0f - 4.0f* (0.5f * (float)Knight.width/6.0f),
    (float)WindowDimension[1]/2.0f - 4.0f * (0.5f * (float)Knight.height)};






SetTargetFPS(120);
while (!WindowShouldClose())
{   
    BeginDrawing();
    ClearBackground(WHITE);
    Vector2 Direction{};
    Rectangle Source{0.f, 0.f, (float)Knight.width/6.f, (float)Knight.height};

    Rectangle Dest{
                    KnightPos.x,
                    KnightPos.y,
                    4.0f * (float)Knight.width/6.f,
                    4.0f * (float)Knight.height
                    };

    Vector2 origin{};

    if (IsKeyDown(KEY_A)) Direction.x -= 1.0;
    if (IsKeyDown(KEY_D)) Direction.x += 1.0;
    if (IsKeyDown(KEY_S)) Direction.y += 1.0;
    if (IsKeyDown(KEY_W)) Direction.y -= 1.0;

    if (Vector2Length(Direction) != 0.0 )
    {
        // Set MapPos based on our movement vector so that we can move our map around
        MapPos = Vector2Subtract(MapPos,Vector2Scale(Vector2Normalize(Direction),Speed));       
    }
    
    
    // Draw the map
    DrawTextureEx(Map,MapPos,0,4,WHITE);

    //Draw Knight
    DrawTexturePro(Knight,Source,Dest,origin,0.f,WHITE);



    EndDrawing();
}





CloseWindow();    
}
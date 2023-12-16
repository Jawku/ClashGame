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




SetTargetFPS(120);
while (!WindowShouldClose())
{   
    BeginDrawing();
    ClearBackground(WHITE);
    Vector2 Direction{};

    if (IsKeyDown(KEY_A)) Direction.x -= 1.0;
    if (IsKeyDown(KEY_D)) Direction.x += 1.0;
    if (IsKeyDown(KEY_S)) Direction.y += 1.0;
    if (IsKeyDown(KEY_W)) Direction.y -= 1.0;

    if (Vector2Length(Direction) != 0.0 )
    {
        // Set MapPos based on our movement vector so that we can move our map around
        MapPos = Vector2Subtract(MapPos,Vector2Scale(Vector2Normalize(Direction),Speed));
    }
    
    
        
        
    
    




    
    DrawTextureEx(Map,MapPos,0,4,WHITE);



    EndDrawing();
}





CloseWindow();    
}
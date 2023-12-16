#include <cstdio>
#include "raylib.h"



int main()
{
    const int WindowDimension[2]{768, 768};

InitWindow(WindowDimension[0],WindowDimension[1],"Clash Of Titi");

// Loading map:
Texture2D Map = LoadTexture("Textures/FirstMap.png");
Vector2 MapPos{0.0,0.0};




SetTargetFPS(120);
while (!WindowShouldClose())
{   
    BeginDrawing();
    ClearBackground(WHITE);
    
    DrawTextureEx(Map,MapPos,0,4,WHITE);



    EndDrawing();
}





CloseWindow();    
}
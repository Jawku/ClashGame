#include <cstdio>
#include "raylib.h"
#include "raymath.h"
#include "character.h"
#include "Prop.h"


/////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    const int WindowDimension[2]{400, 400};

    InitWindow(WindowDimension[0], WindowDimension[1], "Clash Of Titi");

    // Loading map:
    Texture2D Map = LoadTexture("Textures/FirstMap.png");
    Vector2 MapPos{0.0, 0.0};
    const float mapScale{4.f};

    // Initialization of our character class instance:
    //*We're not longer using function for screen pos - we are using construct arguments for that:
    character knight{WindowDimension[0],WindowDimension[1]};

    // Initialization of Props array

    Prop props[3]{
        Prop{Vector2 {200.f,300.f},LoadTexture("Textures/nature_tileset/Rock.png")},
        Prop{Vector2 {400.f,500.f},LoadTexture("Textures/nature_tileset/log.png")},
        Prop{Vector2 {600.f,700.f},LoadTexture("Textures/nature_tileset/Rock.png")}
    };

    
    SetTargetFPS(90);
    while (!WindowShouldClose())s
    {
        BeginDrawing();
        ClearBackground(WHITE);

        // We need to move our map in opposit direction of our WorldPos
        // World pos - vector that defines where we want to move our character.        
        MapPos = Vector2Scale(knight.getWorldPos(),-1.f);

        // Draw the map
        DrawTextureEx(Map, MapPos, 0,mapScale, WHITE);


        //Draw the props from prop array        
        for (auto prop : props)
        {
            prop.Render(knight.getWorldPos());
        }
        
        // Doing evrything that has to be done each frame in our character class with usage of tick function
        knight.tick(GetFrameTime());

        // Check if character is not outside of map pos bound - stays on playable area
        if (knight.getWorldPos().x < 0.f ||
            knight.getWorldPos().y < 0.f ||
            knight.getWorldPos().x + WindowDimension[0] > Map.width * mapScale  ||
            knight.getWorldPos().y + WindowDimension[1] > Map.height * mapScale)
        {
            knight.undoMovement();   
        }
        
        // Check props collisions
        for (auto prop : props)
        {
            if (CheckCollisionRecs(knight.get_collision_rec(),prop.get_collision_rec(knight.getWorldPos())))
            {
                knight.undoMovement();
            }
            
        }
        
        


        EndDrawing();
    }

    CloseWindow();
}
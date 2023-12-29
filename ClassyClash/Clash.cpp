#include <cstdio>
#include "raylib.h"
#include "raymath.h"
#include "character.h"
#include "Prop.h"
#include "Enemy.h"


/////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    const int WindowDimension[2]{500, 500};

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

    // Initialization of Enemys

    Enemy Goblin{
        Vector2{}, 
        LoadTexture("Textures/characters/goblin_idle_spritesheet.png"),
        LoadTexture("Textures/characters/goblin_run_spritesheet.png")
        };
    
    Goblin.SetTarget(&knight);
    
    SetTargetFPS(90);
    while (!WindowShouldClose())
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
            //Debug of colsion rectangles for props
            //DrawRectangle(prop.get_collision_rec(knight.getWorldPos()).x,prop.get_collision_rec(knight.getWorldPos()).y,prop.get_collision_rec(knight.getWorldPos()).width,prop.get_collision_rec(knight.getWorldPos()).height,RED);
            //DrawRectangle(knight.get_collision_rec().x,knight.get_collision_rec().y,knight.get_collision_rec().width,knight.get_collision_rec().height,RED);
            if (CheckCollisionRecs(knight.get_collision_rec(),prop.get_collision_rec(knight.getWorldPos())))
            {
                knight.undoMovement();
            }
            
        }
        
        
         //Goblin drawing:
        Goblin.tick(GetFrameTime());


        EndDrawing();
    }

    CloseWindow();
}
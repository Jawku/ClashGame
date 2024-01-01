#include "character.h"
#include "raylib.h"
#include "raymath.h"


character :: character(int winWidth, int winHeight) :
windowWidth(winWidth),
windowHeight(winHeight)

{
    width = texture.width / maxFrame;
    height = texture.height;
    
}

// Where we spawn our character
Vector2 character::GetScreenPos()
{
    return Vector2{
        static_cast<float>(windowWidth) / 2.0f - scale * (0.5f * width),
        static_cast<float>(windowHeight) / 2.0f - scale * (0.5f * height)
                  };

}

void character::tick(float deltaTime)
{
    
    if (!GetAlive()) return;  

    
    // Player input definition:    
    if (IsKeyDown(KEY_A))
        Velocity.x -= 1.0;
    if (IsKeyDown(KEY_D))
        Velocity.x += 1.0;
    if (IsKeyDown(KEY_S))
        Velocity.y += 1.0;
    if (IsKeyDown(KEY_W))
        Velocity.y -= 1.0;


    BaseCharacter :: tick(deltaTime);

    Vector2 origin{};
    Vector2 originOffset{};
    float Rotation{};

    if (rightLeft > 0.f)
    {
        origin = {0.f,Weapon.height * scale};
        originOffset = {40.f, 55.f};
        WeaponCollisionRec = {GetScreenPos().x + originOffset.x,
                            GetScreenPos().y + originOffset.y - (Weapon.height * scale),
                            Weapon.width * scale,
                            Weapon.height * scale
                            };

        
       Rotation = IsMouseButtonDown(MOUSE_BUTTON_LEFT) ? 35.f : 0.f;

    }
    else
    {
        origin = {Weapon.width * scale, Weapon.height * scale};
        originOffset = {25.f, 55.f};
        WeaponCollisionRec = {GetScreenPos().x + originOffset.x - (Weapon.width * scale),
                            GetScreenPos().y + originOffset.y - (Weapon.height * scale),
                            Weapon.width * scale,
                            Weapon.height * scale
                            };
        Rotation = IsMouseButtonDown(MOUSE_BUTTON_LEFT) ? -35.f : 0.f;
    }

    //Draw sword
    Rectangle source{0.f,0.f,static_cast<float>(Weapon.width) * rightLeft ,static_cast<float>(Weapon.height)};
    Rectangle Dest {GetScreenPos().x + originOffset.x, 
                    GetScreenPos().y + originOffset.y, 
                    Weapon.width * scale, 
                    Weapon.height * scale
                    };
                    
    DrawTexturePro(Weapon,source,Dest,origin,Rotation,WHITE);

   /* DrawRectangleLines(WeaponCollisionRec.x,
                        WeaponCollisionRec.y,
                        WeaponCollisionRec.width,
                        WeaponCollisionRec.height,
                        RED);
    */


}


void character :: TakeDamage(float damage)
{
    health -= damage;
    if (health <= 0.f)
    {
        SetAlive(false);
    }
    
}

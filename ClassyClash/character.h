#ifndef CHARACTER_H
#define CHARACTER_H

#include "raylib.h"
#include "raymath.h"
#include "BaseCharacter.h"


class character : public BaseCharacter
{
public:
      
    character(int winWidth, int winHeight);
    virtual void tick(float deltaTime) override; 
    virtual Vector2 GetScreenPos() override;   

private:
   int windowWidth{};
   int windowHeight{};
   Texture2D Weapon{LoadTexture("Textures/characters/weapon_sword.png")};
   Rectangle WeaponCollisionRec {};
    
};

#endif
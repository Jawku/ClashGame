#include "raylib.h"
#include "raymath.h"
#ifndef BASE_CHARACTER_H
#define BASE_CHARACTER_H
class BaseCharacter
{
    public:
        BaseCharacter();
        Vector2 getWorldPos() { return worldPos; }
        void undoMovement();
        Rectangle get_collision_rec();
        virtual void tick(float deltaTime);
        virtual Vector2 GetScreenPos() = 0; // Pure virtual function ( = 0 makes it that) -> 
        //Because of this Base characeter becomes "Abstract Class" - > WE CANT CREATE INSTANCE OF IT ONLY WE CAN CREATE INSTANCES OF CHILD CLASSES !!!!!
        bool GetAlive() {return Alive;}
        void SetAlive(bool isAlive) {Alive = isAlive; }
        
    protected:
        Texture2D texture{LoadTexture("Textures/characters/knight_idle_spritesheet.png")};
        Texture2D idle{LoadTexture("Textures/characters/knight_idle_spritesheet.png")};
        Texture2D run{LoadTexture("Textures/characters/knight_run_spritesheet.png")};
        Vector2 screenPos{};
        Vector2 worldPos{};
        Vector2 worldPosLastFrame{};

        // 1: facing right, -1 facing left
        float rightLeft{1};
        // animation variables
        int maxFrame{6};
        int frame{0};
        float updateTime{1.f / 12.f};
        float runningTime{};
        float speed{4.f};

        // variables for constructor - smth that we never want to be changed in our class
        float width{};
        float height{};

        float scale{4.0f};
        Vector2 Velocity{};
        

    private:

    bool Alive{true};
    
    

};

#endif
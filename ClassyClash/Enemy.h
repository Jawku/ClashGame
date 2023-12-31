#include "raylib.h"
#include "raymath.h"
#include "BaseCharacter.h"
#include "character.h"

class Enemy : public BaseCharacter
{

public:

    Enemy(Vector2 pos, Texture2D idle_texture, Texture2D run_texture);   
    virtual void tick(float deltaTime) override;
    void SetTarget(character* character) {target = character;};
    virtual Vector2 GetScreenPos() override;
    
   
private: 

    character* target;
    float damagePerSec{10.f};
    float Radius{25.f};
    float Aggro{200.f};

};
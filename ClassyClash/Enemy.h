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
   
private: 

    character* target;

};
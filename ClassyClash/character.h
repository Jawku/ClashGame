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

private:
   
    
};

#endif
#include "Prop.h"
#include "raylib.h"
#include "raymath.h"

Prop::Prop(Vector2 pos, Texture2D tex):
world_pos(pos),
texture(tex)
{

}

void Prop::Render(Vector2 knightPos)
{
    Vector2 screenPos = Vector2Subtract(world_pos, knightPos);
    DrawTextureEx(texture, screenPos,0.f,scale,WHITE);
}

Rectangle Prop :: get_collision_rec(Vector2 knightPos)
{
    Vector2 screenPos = Vector2Subtract(world_pos, knightPos);
    return Rectangle{
                    screenPos.x,
                    screenPos.y,
                    texture.width*scale,
                    texture.height*scale
    };
                    
}
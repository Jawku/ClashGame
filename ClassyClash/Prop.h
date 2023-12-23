#include "raylib.h"
#include "raymath.h"

class Prop
{
    public:
    Prop(Vector2 pos, Texture2D tex);
    void Render(Vector2 knightPos);
    Rectangle get_collision_rec(Vector2 knightPos);

    private:
    Texture2D texture{};
    Vector2 world_pos{};
    float scale = 4.f;
    Rectangle collision{};

};
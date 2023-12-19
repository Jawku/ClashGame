#include "raylib.h"
#include "raymath.h"

class character
{
public:
    Vector2 getWorldPos() { return worldPos; }
    void setScreenPos(int winWidth, int winHeight);
    void tick(float deltaTime);
    character();

private:
    Texture2D texture{LoadTexture("Textures/characters/knight_idle_spritesheet.png")};
    Texture2D idle{LoadTexture("Textures/characters/knight_idle_spritesheet.png")};
    Texture2D run{LoadTexture("Textures/characters/knight_run_spritesheet.png")};
    Vector2 screenPos{};
    Vector2 worldPos{};

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
};
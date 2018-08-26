#ifndef CHARACTER_H
#define CHARACTER_H
#include "global.h"

using namespace sf;

class Character {
private:
    Sprite sprite;
    Texture texture;
    RectangleShape collisionBox;
    Vector2f movSpeed;
    char movDir;
    
    int fExitFailure();

public:
    Character(const int xPos, const int yPos);
    bool isGrid(Sprite background);

    void draw(RenderWindow &window);
    void update(const short multVel, View &walkingCamera);

    // Getters
    Sprite &getCharSprite();
    RectangleShape &getCharCollisionBox();
    Vector2f &getMovSpeed();
    char &getMovDir();
};

#endif

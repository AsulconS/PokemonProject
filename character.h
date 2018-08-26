#ifndef CHARACTER_H
#define CHARACTER_H
#include "global.h"

using namespace sf;

class Character {
private:
    Sprite sprite;
    Texture texture;
    RectangleShape collisionBox;
    short movSpeed;
    char movDir;
    
    int fExitFailure();

public:
    Character(const int xPos, const int yPos);
    bool isGrid(Sprite background);

    void draw(RenderWindow &window);
    void update(View &walkingCamera);

    // Getters
    Sprite &getCharSprite();
    RectangleShape &getCharCollisionBox();
    short &getMovSpeed();
    char &getMovDir();
};

#endif

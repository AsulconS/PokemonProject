#ifndef CHARACTER_H
#define CHARACTER_H
#include "global.h"

using namespace sf;

class Character {
private:
    Sprite sprite;
    Texture texture;
    RectangleShape collisionBox;
    int movSpeed;
    char movDir;
    
    int fExitFailure();

public:
    Character(const int xPos, const int yPos, std::string name);
    bool isGrid(Sprite background);

    void draw(RenderWindow &window);
    void update(View &mainCamera);

    // Getters
    Sprite &getCharSprite();
    RectangleShape &getCharCollisionBox();
    int &getMovSpeed();
    char &getMovDir();
};

#endif

#ifndef CHARACTER_H
#define CHARACTER_H
#include "global.h"
#include "hud.h"

class Character {
public:
    Character(const int xPos, const int yPos, std::string name);

    void draw(sf::RenderWindow &window);
    void update(sf::View &mainCamera);
    bool isGrid(sf::Sprite background);

// Getters
    sf::Sprite &getSprite();
    sf::RectangleShape &getCollisionBox();
    HUD &getHUD();
    int &getMovSpeed();
    char &getMovDir();
// -------

private:
    int fExitFailure();

private:
    sf::Sprite sprite;
    sf::Texture texture;
    sf::RectangleShape collisionBox;
    HUD playerHUD;
    int movSpeed;
    char movDir; 
};

#endif

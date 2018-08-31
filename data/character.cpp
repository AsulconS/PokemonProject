#include "character.h"

Character::Character(const int xPos,  const int yPos, std::string name) {
    if(!texture.loadFromFile("resources/images/characters/" + name + ".png")) {
        system("echo No se pudo cargar la textura&pause");
        fExitFailure();
    }
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(24, 36, 16, 20));
    sprite.setScale(sf::Vector2f(SCALECONST, SCALECONST));
    sprite.setPosition(xPos * SCALECONST, yPos * SCALECONST);
    // Drawn sf::Sprite X: 112  Y: 68

    collisionBox.setSize(sf::Vector2f(16, 16));
    collisionBox.setScale(sf::Vector2f(SCALECONST, SCALECONST));
    collisionBox.setPosition(xPos * SCALECONST, (yPos + 4) * SCALECONST);
    // Collision box X: 112  Y: 72
    movSpeed = MOVSPEED;
}

void Character::draw(sf::RenderWindow &window) { window.draw(sprite); }

void Character::update(sf::View &mainCamera) {
    switch(movDir) {
        case 'u':
            sprite.setTextureRect(sf::IntRect(24, 68, 16, 20));
            sprite.setOrigin(sf::Vector2f(0, 0));
            sprite.setScale(sf::Vector2f(SCALECONST, SCALECONST));
            sprite.move(0, -movSpeed * SCALECONST); collisionBox.move(0, -movSpeed * SCALECONST);
            mainCamera.move(0, -movSpeed * SCALECONST); playerHUD.move(0, -movSpeed * SCALECONST);
            break;
        case 'd':
            sprite.setTextureRect(sf::IntRect(24, 36, 16, 20));
            sprite.setOrigin(sf::Vector2f(0, 0));
            sprite.setScale(sf::Vector2f(SCALECONST, SCALECONST));
            sprite.move(0, movSpeed * SCALECONST); collisionBox.move(0, movSpeed * SCALECONST);
            mainCamera.move(0, movSpeed * SCALECONST); playerHUD.move(0, movSpeed * SCALECONST);
            break;
        case 'r':
            sprite.setTextureRect(sf::IntRect(24, 100, 16, 20));
            sprite.setOrigin(sf::Vector2f(16, 0));
            sprite.setScale(sf::Vector2f(-SCALECONST, SCALECONST));
            sprite.move(movSpeed * SCALECONST, 0); collisionBox.move(movSpeed * SCALECONST, 0);
            mainCamera.move(movSpeed * SCALECONST, 0); playerHUD.move(movSpeed * SCALECONST, 0);
            break;
        case 'l':
            sprite.setTextureRect(sf::IntRect(24, 100, 16, 20));
            sprite.setOrigin(sf::Vector2f(0, 0));
            sprite.setScale(sf::Vector2f(SCALECONST, SCALECONST));
            sprite.move(-movSpeed * SCALECONST, 0); collisionBox.move(-movSpeed * SCALECONST, 0);
            mainCamera.move(-movSpeed * SCALECONST, 0); playerHUD.move(-movSpeed * SCALECONST, 0);
            break;
        default: break;
    }
}

bool Character::isGrid(sf::Sprite background) {
    return (((int)collisionBox.getPosition().x - (int)background.getPosition().x) % (16 * SCALECONST) == 0 &&
            ((int)collisionBox.getPosition().y - (int)background.getPosition().y) % (16 * SCALECONST) == 0    ) ? 1 : 0;
}

sf::Sprite &Character::getSprite() { return sprite; }
sf::RectangleShape &Character::getCollisionBox() { return collisionBox; }
HUD &Character::getHUD() { return playerHUD; }
int &Character::getMovSpeed() { return movSpeed; }
char &Character::getMovDir() { return movDir; }

int Character::fExitFailure() { return EXIT_FAILURE; }

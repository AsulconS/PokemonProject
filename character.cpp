#include "character.h"

using namespace sf;

Character::Character(const int xPos,  const int yPos) {
    // The initial Texture
    if(!texture.loadFromFile("images/red.png")) {
        system("echo No se pudo cargar la textura&pause");
        fExitFailure();
    }
    sprite.setTexture(texture, 0);
    sprite.setTextureRect(IntRect(24, 36, 16, 20));
    sprite.setScale(Vector2f(SCALECONST, SCALECONST));
    sprite.setPosition(xPos * SCALECONST, yPos * SCALECONST);

    collisionBox.setSize(Vector2f(16, 16));
    collisionBox.setScale(Vector2f(SCALECONST, SCALECONST));
    collisionBox.setPosition(xPos * SCALECONST, (yPos + 4) * SCALECONST);
    // Collision box X: 112  Y: 72
}

int Character::fExitFailure() { return EXIT_FAILURE; }

bool Character::isGrid(Sprite background) {
    return (((int)collisionBox.getPosition().x - (int)background.getPosition().x) % (16 * SCALECONST) == 0 &&
            ((int)collisionBox.getPosition().y - (int)background.getPosition().y) % (16 * SCALECONST) == 0    ) ? 1 : 0;
}

Sprite &Character::getCharSprite() { return sprite; }
RectangleShape &Character::getCharCollisionBox() { return collisionBox; }
Vector2f &Character::getMovSpeed() { return movSpeed; }
char &Character::getMovDir() { return movDir; }

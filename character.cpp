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
    movSpeed = 1;
}

int Character::fExitFailure() { return EXIT_FAILURE; }

bool Character::isGrid(Sprite background) {
    return (((int)collisionBox.getPosition().x - (int)background.getPosition().x) % (16 * SCALECONST) == 0 &&
            ((int)collisionBox.getPosition().y - (int)background.getPosition().y) % (16 * SCALECONST) == 0    ) ? 1 : 0;
}

void Character::draw(RenderWindow &window) { window.draw(sprite); }

void Character::update(View &walkingCamera) {
    switch(movDir) {
        case 'u':
            sprite.setTextureRect(IntRect(24, 68, 16, 20));
            sprite.setOrigin(Vector2f(0, 0));
            sprite.setScale(Vector2f(SCALECONST, SCALECONST));
            sprite.move(0, -movSpeed * SCALECONST); collisionBox.move(0, -movSpeed * SCALECONST); walkingCamera.move(0, -movSpeed * SCALECONST);
            break;
        case 'd':
            sprite.setTextureRect(IntRect(24, 36, 16, 20));
            sprite.setOrigin(Vector2f(0, 0));
            sprite.setScale(Vector2f(SCALECONST, SCALECONST));
            sprite.move(0, movSpeed * SCALECONST); collisionBox.move(0, movSpeed * SCALECONST); walkingCamera.move(0, movSpeed * SCALECONST);
            break;
        case 'r':
            sprite.setTextureRect(IntRect(24, 100, 16, 20));
            sprite.setOrigin(Vector2f(16, 0));
            sprite.setScale(Vector2f(-SCALECONST, SCALECONST));
            sprite.move(movSpeed * SCALECONST, 0); collisionBox.move(movSpeed * SCALECONST, 0); walkingCamera.move(movSpeed * SCALECONST, 0);
            break;
        case 'l':
            sprite.setTextureRect(IntRect(24, 100, 16, 20));
            sprite.setOrigin(Vector2f(0, 0));
            sprite.setScale(Vector2f(SCALECONST, SCALECONST));
            sprite.move(-movSpeed * SCALECONST, 0); collisionBox.move(-movSpeed * SCALECONST, 0); walkingCamera.move(-movSpeed * SCALECONST, 0);
            break;
        default: break;
    }
}

Sprite &Character::getCharSprite() { return sprite; }
RectangleShape &Character::getCharCollisionBox() { return collisionBox; }
short &Character::getMovSpeed() { return movSpeed; }
char &Character::getMovDir() { return movDir; }

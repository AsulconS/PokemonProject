#include "background.h"

using namespace sf;

Background::Background(const int xPos, const int yPos, std::string nameOfBg) {
    if(!sourceImage.loadFromFile("resources/images/backgrounds/" + nameOfBg + ".png")) {
        system("echo No se pudo cargar el escenario&pause");
        fExitFailure();
    }
    background.setTexture(sourceImage, 0);
    background.setTextureRect(IntRect(5, 5, 176, 144));
    background.setScale(Vector2f(SCALECONST, SCALECONST));
    background.setPosition(xPos * SCALECONST, yPos * SCALECONST);
}

int Background::fExitFailure() { return EXIT_FAILURE; }

void Background::draw(RenderWindow &window) { window.draw(background); }

Sprite &Background::getBgSprite() { return background; }
Texture &Background::getSrcImage() { return sourceImage; }

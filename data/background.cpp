#include "background.h"

Background::Background(const int xPos, const int yPos, std::string name) {
    if(!sourceImage.loadFromFile("resources/images/backgrounds/" + name + ".png")) {
        system("echo No se pudo cargar el escenario&pause");
        fExitFailure();
    }
    background.setTexture(sourceImage);
    background.setTextureRect(sf::IntRect(5, 5, 176, 144));
    background.setScale(sf::Vector2f(SCALECONST, SCALECONST));
    background.setPosition(xPos * SCALECONST, yPos * SCALECONST);
}

void Background::draw(sf::RenderWindow &window) { window.draw(background); }

sf::Sprite &Background::getSprite() { return background; }
sf::Texture &Background::getSrcImage() { return sourceImage; }

int Background::fExitFailure() { return EXIT_FAILURE; }

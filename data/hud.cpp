#include "hud.h"

HUD::HUD() {
	if(!sourceImage.loadFromFile("resources/images/HUD/pauseMenu.png")) {
        system("echo No se pudo cargar el HUD&pause");
        fExitFailure();
    }
    sprite.setTexture(sourceImage, 0);
    sprite.setScale(sf::Vector2f(SCALECONST, SCALECONST));
    sprite.setPosition(0, 0);
}

void HUD::draw(sf::RenderWindow &window) { window.draw(sprite); }

void HUD::move(const int offsetX, const int offsetY) {
	position.x += offsetX;
	position.y += offsetY;
	sprite.setPosition(position);
}

sf::Sprite &HUD::getHUDSprite() { return sprite; }
sf::Texture &HUD::getSrcImage() { return sourceImage; }
sf::Vector2f &HUD::getPosition() { return position; }

int HUD::fExitFailure() { return EXIT_FAILURE; }

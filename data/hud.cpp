#include "hud.h"

using namespace sf;

HUD::HUD() {
	if(!sourceImage.loadFromFile("resources/images/HUD/pauseMenu.png")) {
        system("echo No se pudo cargar el HUD&pause");
        fExitFailure();
    }
    sprite.setTexture(sourceImage, 0);
    sprite.setScale(Vector2f(SCALECONST, SCALECONST));
    sprite.setPosition(0, 0);
}

int HUD::fExitFailure() { return EXIT_FAILURE; }

void HUD::draw(RenderWindow &window) { window.draw(sprite); }

void HUD::move(const int offsetX, const int offsetY) {
	position.x += offsetX;
	position.y += offsetY;
	sprite.setPosition(position);
}

Sprite &HUD::getHUDSprite() { return sprite; }
Texture &HUD::getSrcImage() { return sourceImage; }
Vector2f &HUD::getPosition() { return position; }

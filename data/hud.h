#ifndef HUD_H
#define HUD_H
#include "global.h"

class HUD {
public:
	HUD();

	void draw(sf::RenderWindow &window);
	void move(const int offsetX, const int offsetY);

// Getters
	sf::Sprite &getHUDSprite();
	sf::Texture &getSrcImage();
	sf::Vector2f &getPosition();
// -------

private:
	int fExitFailure();

private:
	sf::Sprite sprite;
	sf::Texture sourceImage;
	sf::Vector2f position;
};

#endif

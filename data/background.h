#ifndef BACKGROUND_H
#define BACKGROUND_H
#include "global.h"

class Background {
public:
	Background(const int xPos, const int yPos, std::string name);

	void draw(sf::RenderWindow &window);

// Getters
	sf::Sprite &getSprite();
	sf::Texture &getSrcImage();
// -------

private:
	int fExitFailure();

private:
	sf::Sprite background;
	sf::Texture sourceImage;
};

#endif

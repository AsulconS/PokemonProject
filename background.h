#ifndef BACKGROUND_H
#define BACKGROUND_H
#include "global.h"

using namespace sf;

class Background {
private:
	Sprite background;
	Texture sourceImage;

	int fExitFailure();

public:
	Background(const int xPos, const int yPos, std::string nameOfBg);

	void draw(RenderWindow &window);

	Sprite &getBgSprite();
	Texture &getSrcImage();
};

#endif

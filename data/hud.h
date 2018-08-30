#ifndef HUD_H
#define HUD_H
#include "global.h"

using namespace sf;

class HUD {
private:
	Sprite sprite;
	Texture sourceImage;
	Vector2f position;

	int fExitFailure();

public:
	HUD();

	void draw(RenderWindow &window);
	void move(const int offsetX, const int offsetY);

	Sprite &getHUDSprite();
	Texture &getSrcImage();
	Vector2f &getPosition();
};

#endif

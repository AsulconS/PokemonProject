#ifndef GAMETEXT_H
#define GAMETEXT_H
#include "global.h"

using namespace sf;

class GameText {
private:
	Font font;
	Text text;

	int fExitFailure();

public:
	GameText(std::string nameFont, std::string nText);

	void draw(RenderWindow &window);

	Font &getFont();
	Text &getText();
};

#endif

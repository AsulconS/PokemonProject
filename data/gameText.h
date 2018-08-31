#ifndef GAMETEXT_H
#define GAMETEXT_H
#include "global.h"

class GameText {
public:
	GameText(std::string nFont, std::string nText);

	void draw(sf::RenderWindow &window);

// Getters
	sf::Font &getFont();
	sf::Text &getText();
// -------

private:
	int fExitFailure();

private:
	sf::Font font;
	sf::Text text;
};

#endif

#include "gameText.h"

GameText::GameText(std::string nFont, std::string nText) {
    if(!font.loadFromFile("resources/fonts/" + nFont + ".ttf")) {
        system("echo No se pudo cargar las fuentes&pause");
        fExitFailure();
    }
    text.setString(nText);
    text.setFont(font);
}

void GameText::draw(sf::RenderWindow &window) { window.draw(text); }

sf::Font &GameText::getFont() { return font; };
sf::Text &GameText::getText() { return text; };

int GameText::fExitFailure() { return EXIT_FAILURE; }

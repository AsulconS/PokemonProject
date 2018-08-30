#include "gameText.h"

using namespace sf;

GameText::GameText(std::string nameFont, std::string nText) {
    if(!font.loadFromFile("resources/fonts/" + nameFont + ".ttf")) {
        system("echo No se pudo cargar las fuentes&pause");
        fExitFailure();
    }
    text.setString(nText);
    text.setFont(font);
}

int GameText::fExitFailure() { return EXIT_FAILURE; }

void GameText::draw(RenderWindow &window) { window.draw(text); }

Font &GameText::getFont() { return font; };
Text &GameText::getText() { return text; };

#include "global.h"
#include "animation.h"
#include "background.h"
#include "character.h"
#include "gameText.h"
#include "hud.h"
#include "soundFX.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(240 * SCALECONST, 160 * SCALECONST), "Pokemon Project", sf::Style::Close | sf::Style::Titlebar); // WINDOW    The Native Resolution is 240 x 160 px
    sf::View mainCamera(sf::FloatRect(0, 0, 240 * SCALECONST, 160 * SCALECONST)); // CAMERA

    Character character(CHARX, CHARY, "red"); // CHARACTER
    Background background(32, -24, "pallet_town_i"); // BACKGROUND
    GameText gameText("pokemonFont", "CS-UNSA 2018");

    // MUSIC
    sf::Music music;
    if(!music.openFromFile("resources/music/06_PalletTownTheme.flac")) {
        system("echo No se pudo cargar la musica&pause");
        return EXIT_FAILURE;
    }
    SoundFX sound("swish_3");

    music.play(); // Play the music

    window.setFramerateLimit(60);
    bool isPMenu = 0;

    // Start the game loop
    while(window.isOpen())
    {
        sf::Event evnt; // Create the event
        while(window.pollEvent(evnt))
        {
            // Close window: exit
            switch(evnt.type) {
                case sf::Event::Closed:
                    system("echo Estuvo shido siono? xd");
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    switch(evnt.key.code) {
                        case sf::Keyboard::Return:
                            if(character.isGrid(background.getSprite()))
                                isPMenu = isPMenu ? 0 : 1;
                            sound.play();
                            system("echo Menu");
                            break;
                        default: break;
                    } break;
                default: break;
            }
        }
        // If a key is pressed, character's movDir will change
        if(character.isGrid(background.getSprite()) && !isPMenu) {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) character.getMovSpeed() = MOVSPEED * 2;
            else character.getMovSpeed() = MOVSPEED;
            char &charMovDir = character.getMovDir();
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                charMovDir = 'u';
            } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                charMovDir = 'd';
            } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                charMovDir = 'r';
            } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                charMovDir = 'l';
            } else charMovDir = 'i';
        }
        
        character.update(mainCamera);

        window.setView(mainCamera);
        window.clear(); // Clear screen
        background.draw(window); // Draw the background
        character.draw(window); // Draw the character
        gameText.draw(window); // Draw the string
        // window.draw(charCollisionBox);
        if(isPMenu) character.getHUD().draw(window);
        window.display(); // Update the window
    }

    return EXIT_SUCCESS;
}

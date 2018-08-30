#include "global.h"
#include "character.h"
#include "hud.h"
#include "background.h"
#include "gameText.h"
#include "soundFX.h"

using namespace sf;

int main() {
    RenderWindow window(VideoMode(240 * SCALECONST, 160 * SCALECONST), "Pokemon Project"); // WINDOW    The Native Resolution is 240 x 160 px
    View mainCamera(FloatRect(0, 0, 240 * SCALECONST, 160 * SCALECONST)); // CAMERA

    Character character(CHARX, CHARY, "red"); // CHARACTER
    Background background(32, -24, "pallet_town_i"); // BACKGROUND
    GameText gameText("arial", "CS-UNSA 2018");

    // MUSIC
    Music music;
    if(!music.openFromFile("resources/music/nice_music.wav")) {
        system("echo No se pudo cargar la musica&pause");
        return EXIT_FAILURE;
    }
    SoundFX sound("swish_3");

    music.play(); // Play the music
    sound.play(); // Play the sound

    window.setFramerateLimit(60);
    bool isPMenu = 0;

    // Start the game loop
    while(window.isOpen())
    {
        Event event; // Create the event
        while(window.pollEvent(event))
        {
            // Close window: exit
            switch(event.type) {
                case Event::Closed:
                    system("echo Estuvo shido siono? xd");
                    window.close();
                    break;
                case Event::KeyPressed:
                    switch(event.key.code) {
                        case Keyboard::Space:
                            sound.play();
                            system("echo Se presiona");
                            break;
                        case Keyboard::Return:
                            if(character.isGrid(background.getBgSprite()))
                                isPMenu = isPMenu ? 0 : 1;
                            break;
                        default: break;
                    } break;
                default: break;
            }
        }
        // If a key is pressed, character's movDir will change
        if(character.isGrid(background.getBgSprite()) && !isPMenu) {
            if(Keyboard::isKeyPressed(Keyboard::Z)) character.getMovSpeed() = MOVSPEED * 2;
            else character.getMovSpeed() = MOVSPEED;
            char &charMovDir = character.getMovDir();
            if(Keyboard::isKeyPressed(Keyboard::Up)) {
                charMovDir = 'u';
            } else if(Keyboard::isKeyPressed(Keyboard::Down)) {
                charMovDir = 'd';
            } else if(Keyboard::isKeyPressed(Keyboard::Right)) {
                charMovDir = 'r';
            } else if(Keyboard::isKeyPressed(Keyboard::Left)) {
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
        if(isPMenu) character.getPlayerHUD().draw(window);
        window.display(); // Update the window
    }
    return EXIT_SUCCESS;
}
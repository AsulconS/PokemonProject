#include "global.h"
#include "character.h"
#include "background.h"

using namespace sf;

int main() {
    // WINDOW and VIEW
    RenderWindow window(VideoMode(240 * SCALECONST, 160 * SCALECONST), "Pokemon Project"); // The Native Resolution is 240 x 160 px
    View walkingCamera(FloatRect(0, 0, 240 * SCALECONST, 160 * SCALECONST));

    Character character(112, 68); // CHARACTER
    Background background(32, -24, "pallet_town_i"); // BACKGROUND

    // TEXT
    Font font;
    if(!font.loadFromFile("fonts/arial.ttf")) {
        system("echo No se pudo cargar las fuentes&pause");
        return EXIT_FAILURE;
    }
    Text text("CS-UNSA 2018", font);

    // MUSIC
    Music music;
    if(!music.openFromFile("music/nice_music.wav")) {
        system("echo No se pudo cargar la musica&pause");
        return EXIT_FAILURE;
    }
    
    // SOUND
    SoundBuffer buffer;
    if(!buffer.loadFromFile("sounds/swish_3.wav")) {
        system("echo No se pudo cargar el sonido&pause");
        return EXIT_FAILURE;
    }
    Sound sound;
    sound.setBuffer(buffer);

    music.play(); // Play the music
    sound.play(); // Play the sound

    Keyboard::Key lastKey = Keyboard::Unknown; // lastKey Variable

    window.setFramerateLimit(60);

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
                    } break;
            }
        }
        // If a key is pressed, character's movDir will change
        if(character.isGrid(background.getBgSprite())) {
            char &charMovDir = character.getMovDir();
            if(Keyboard::isKeyPressed(Keyboard::Up)) {
                charMovDir = 'u';
                lastKey = event.key.code;
            } else if(Keyboard::isKeyPressed(Keyboard::Down)) {
                charMovDir = 'd';
                lastKey = event.key.code;
            } else if(Keyboard::isKeyPressed(Keyboard::Right)) {
                charMovDir = 'r';
                lastKey = event.key.code;
            } else if(Keyboard::isKeyPressed(Keyboard::Left)) {
                charMovDir = 'l';
                lastKey = event.key.code;
            } else charMovDir = 'i';
        }
        
        character.update(1, walkingCamera);

        window.clear(); // Clear screen
        window.setView(walkingCamera);
        background.draw(window); // Draw the background
        character.draw(window); // Draw the character
        // window.draw(charCollisionBox);
        window.draw(text); // Draw the string
        window.display(); // Update the window
    }
    return EXIT_SUCCESS;
}

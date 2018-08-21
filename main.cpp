#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>

#include<cstdlib>

#define MOVSPEED 1
#define SCALECONST 5

using namespace sf;

int fExitFailure() { return EXIT_FAILURE; }

class Character {
private:
    Sprite sprite;
    Texture texture;
    RectangleShape collisionBox;
    Vector2f movSpeed;
    char movDir;

public:
    Character() {
        // The initial Texture
        if(!texture.loadFromFile("images/red.png")) {
            system("echo No se pudo cargar la textura&pause");
            fExitFailure();
        }
        sprite.setTexture(texture, 0);
        sprite.setTextureRect(IntRect(24, 36, 16, 20));
        sprite.setScale(Vector2f(SCALECONST, SCALECONST));
        sprite.setPosition(112 * SCALECONST, 68 * SCALECONST);
        
        collisionBox.setSize(Vector2f(16, 16));
        collisionBox.setScale(Vector2f(SCALECONST, SCALECONST));
        collisionBox.setPosition(112 * SCALECONST, 72 * SCALECONST);
    }

    bool isGrid(Sprite background) {
        return (((int)collisionBox.getPosition().x - (int)background.getPosition().x) % (16 * SCALECONST) == 0 &&
                ((int)collisionBox.getPosition().y - (int)background.getPosition().y) % (16 * SCALECONST) == 0    ) ? 1 : 0;
    }

    Sprite &getCharSprite() { return sprite; }
    RectangleShape &getCharCollisionBox() { return collisionBox; }
    Vector2f &getMovSpeed() { return movSpeed; }
    char &getMovDir() { return movDir; }
};

int main() {
    // WINDOW and VIEW
    RenderWindow window(VideoMode(240 * SCALECONST, 160 * SCALECONST), "Pokemon Project"); // The Native Resolution is 240 x 160 px
    View walkingCamera(FloatRect(0, 0, 240 * SCALECONST, 160 * SCALECONST));

    // CHARACTER
    Character character;

    // BACKGROUND
    Texture texture2;
    if(!texture2.loadFromFile("images/pallet_town_i.png")) {
        system("echo No se pudo cargar la textura&pause");
        return EXIT_FAILURE;
    }
    Sprite background(texture2, IntRect(5, 5, 176, 144));
    background.setScale(Vector2f(SCALECONST, SCALECONST));
    background.setPosition(32 * SCALECONST, -24 * SCALECONST);

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

    // Play the music
    music.play();
    // Play the sound
    sound.play();

    // lastKey Variable
    Keyboard::Key lastKey = Keyboard::Unknown;

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
        if(character.isGrid(background)) {
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
        // Step Movement
        Sprite &charSprite = character.getCharSprite();
        RectangleShape &charCollisionBox = character.getCharCollisionBox();
        switch(character.getMovDir()) {
            case 'u':
                charSprite.setTextureRect(IntRect(24, 68, 16, 20));
                charSprite.setOrigin(Vector2f(0, 0));
                charSprite.setScale(Vector2f(SCALECONST, SCALECONST));
                charSprite.move(0, -MOVSPEED * SCALECONST); charCollisionBox.move(0, -MOVSPEED * SCALECONST); walkingCamera.move(0, -MOVSPEED * SCALECONST);
                break;
            case 'd':
                charSprite.setTextureRect(IntRect(24, 36, 16, 20));
                charSprite.setOrigin(Vector2f(0, 0));
                charSprite.setScale(Vector2f(SCALECONST, SCALECONST));
                charSprite.move(0, MOVSPEED * SCALECONST); charCollisionBox.move(0, MOVSPEED * SCALECONST); walkingCamera.move(0, MOVSPEED * SCALECONST);
                break;
            case 'r':
                charSprite.setTextureRect(IntRect(24, 100, 16, 20));
                charSprite.setOrigin(Vector2f(16, 0));
                charSprite.setScale(Vector2f(-SCALECONST, SCALECONST));
                charSprite.move(MOVSPEED * SCALECONST, 0); charCollisionBox.move(MOVSPEED * SCALECONST, 0); walkingCamera.move(MOVSPEED * SCALECONST, 0);
                break;
            case 'l':
                charSprite.setTextureRect(IntRect(24, 100, 16, 20));
                charSprite.setOrigin(Vector2f(0, 0));
                charSprite.setScale(Vector2f(SCALECONST, SCALECONST));
                charSprite.move(-MOVSPEED * SCALECONST, 0); charCollisionBox.move(-MOVSPEED * SCALECONST, 0); walkingCamera.move(-MOVSPEED * SCALECONST, 0);
                break;
            default: break;
        }
        // Clear screen
        window.clear();
        window.setView(walkingCamera);
        // Draw the background
        window.draw(background);
        // Draw the sprite
        window.draw(charSprite);
        // window.draw(charCollisionBox);
        // Draw the string
        window.draw(text);
        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}

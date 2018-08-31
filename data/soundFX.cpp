#include "soundFX.h"

SoundFX::SoundFX(std::string nameSound) {
	if(!buffer.loadFromFile("resources/sounds/" + nameSound + ".wav")) {
        system("echo No se pudo cargar el sonido&pause");
        fExitFailure();
    }
    sound.setBuffer(buffer);
}

void SoundFX::play() { sound.play(); }

sf::SoundBuffer &SoundFX::getBuffer() { return buffer; }
sf::Sound &SoundFX::getSound() { return sound; }

int SoundFX::fExitFailure() { return EXIT_FAILURE; }

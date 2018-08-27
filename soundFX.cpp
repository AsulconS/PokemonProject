#include "soundFX.h"

using namespace sf;

SoundFX::SoundFX(std::string nameSound) {
	if(!buffer.loadFromFile("resources/sounds/" + nameSound + ".wav")) {
        system("echo No se pudo cargar el sonido&pause");
        fExitFailure();
    }
    sound.setBuffer(buffer);
}

int SoundFX::fExitFailure() { return EXIT_FAILURE; }

void SoundFX::play() { sound.play(); }

SoundBuffer &SoundFX::getBuffer() { return buffer; }
Sound &SoundFX::getSound() { return sound; }

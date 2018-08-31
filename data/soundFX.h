#ifndef SOUNDFX_H
#define SOUNDFX_H
#include "global.h"

class SoundFX {
public:
	SoundFX(std::string nameSound);

	void play();

// Getters
	sf::SoundBuffer &getBuffer();
	sf::Sound &getSound();
// -------

private:
	int fExitFailure();

private:
	sf::SoundBuffer buffer;
	sf::Sound sound;
};

#endif

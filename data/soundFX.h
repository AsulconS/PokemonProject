#ifndef SOUNDFX_H
#define SOUNDFX_H
#include "global.h"

using namespace sf;

class SoundFX {
private:
	SoundBuffer buffer;
	Sound sound;

	int fExitFailure();

public:
	SoundFX(std::string nameSound);

	void play();

	SoundBuffer &getBuffer();
	Sound &getSound();
};

#endif

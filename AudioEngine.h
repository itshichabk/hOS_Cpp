/*
*	hOS Audio Engine
*	================
* 
*	Powered by the miniaudio library! (https://github.com/mackron/miniaudio)
*/

#pragma once
#include "miniaudio.h"

class AudioEngine
{
private:
	ma_engine _engine;

public:
	AudioEngine();
	~AudioEngine();

	int initialize();

	void playAudio(std::string file);

};
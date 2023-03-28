#define MINIAUDIO_IMPLEMENTATION

#include <string>
#include <curses.h>
#include "AudioEngine.h"


int AudioEngine::initialize()
{
    ma_result result;

    result = ma_engine_init(NULL, &_engine);
    if (result != MA_SUCCESS) {
        printf("Failed to initialize audio engine.");
        return -1;
    }

    return 0;
}

AudioEngine::AudioEngine()
{
    initialize();
}

AudioEngine::~AudioEngine()
{
    ma_engine_uninit(&_engine);
}

void AudioEngine::playAudio(std::string file)
{
    std::string filePath = "sounds/" + file;
    ma_engine_play_sound(&_engine, filePath.c_str(), NULL);
}
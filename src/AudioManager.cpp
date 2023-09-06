#include "AudioManager.h"
#include <SDL_filesystem.h>

AudioManager* AudioManager::sInstance = NULL;

AudioManager::AudioManager() {

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) < 0) {
		std::cout << "Mixer initialization error: " << Mix_GetError() << std::endl;
	}
}

AudioManager::~AudioManager() {
	Mix_Quit();
}

AudioManager* AudioManager::Instance() {

	if (sInstance == NULL) {
		sInstance = new AudioManager();
	}

	return sInstance;
}

void AudioManager::Release() {

	delete sInstance;
	sInstance = NULL;
}

void AudioManager::PlayMusic(std::string filename, int loops) {

	Mix_PlayMusic(GetMusic(filename), loops);
}

void AudioManager::PauseMusic() {

	if (Mix_PlayingMusic() != 0) {
		Mix_PauseMusic();
	}
}

void AudioManager::ResumeMusic() {

	if (Mix_PausedMusic() != 0) {
		Mix_ResumeMusic();
	}
}

void AudioManager::PlaySFX(std::string filename, int loops, int channel) {

	Mix_PlayChannel(channel, GetSFX(filename), loops);
}

Mix_Music* AudioManager::GetMusic(std::string filename) {

	std::string fullpath = "assets/" + filename;

	if (musics[fullpath] == nullptr) {

		musics[fullpath] = Mix_LoadMUS(fullpath.c_str());
		if (musics[fullpath] == NULL) {
			std::cout << "Error loading music file: " << fullpath << "Error: " << Mix_GetError() << std::endl;
		}
	}

	return musics[fullpath];
}

Mix_Chunk* AudioManager::GetSFX(std::string filename) {

	std::string fullpath = "assets/" + filename;

	if (sfx[fullpath] == nullptr) {

		sfx[fullpath] = Mix_LoadWAV(fullpath.c_str());
		if (sfx[fullpath] == NULL) {
			std::cout << "Error loading SFX file: " << fullpath.c_str() << "Error: " << Mix_GetError() << std::endl;
		}
	}

	return sfx[fullpath];
}

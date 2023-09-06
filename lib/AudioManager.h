#ifndef _AUDIOMANAGER_H
#define _AUDIOMANAGER_H

#include <SDL_mixer.h>
#include <map>
#include <string>
#include <iostream>

/**
 * @class AudioManager
 * @brief Manages audio assets and playback.
 *
 * The `AudioManager` class is responsible for managing audio assets such as music and sound effects,
 * as well as controlling audio playback within the game.
 */
class AudioManager {

private:

	static AudioManager* sInstance;

	std::map<std::string, Mix_Music*> musics;
	std::map<std::string, Mix_Chunk*> sfx;

public:

	/**
	 * @brief Get the instance of the AudioManager.
	 *
	 * This function returns the singleton instance of the AudioManager class.
	 * @return A pointer to the AudioManager instance.
	 */
	static AudioManager* Instance();

	/**
	 * @brief Release the AudioManager instance.
	 *
	 * Releases the AudioManager instance and frees associated resources.
	 */
	static void Release();


	/**
	 * @brief Get a music asset.
	 *
	 * Retrieves a music asset from the AudioManager using its filename.
	 *
	 * @param filename The filename of the music asset.
	 * @return A pointer to the Mix_Music if found, or nullptr if not found.
	 */
	Mix_Music* GetMusic(std::string filename);

	/**
	 * @brief Get a sound effect asset.
	 *
	 * Retrieves a sound effect asset from the AudioManager using its filename.
	 *
	 * @param filename The filename of the sound effect asset.
	 * @return A pointer to the Mix_Chunk if found, or nullptr if not found.
	 */
	Mix_Chunk* GetSFX(std::string filename);

	/**
	 * @brief Play music.
	 *
	 * Plays a music asset specified by its filename.
	 *
	 * @param filename The filename of the music asset to play.
	 * @param loops The number of times to loop the music (-1 for infinite loop, 0 for no loop).
	 */
	void PlayMusic(std::string filename, int loops = -1);

	/**
	 * @brief Pause currently playing music.
	 *
	 * Pauses the currently playing music.
	 */
	void PauseMusic();

	/**
	 * @brief Resume paused music.
	 *
	 * Resumes playback of paused music.
	 */
	void ResumeMusic();

	/**
	 * @brief Play a sound effect.
	 *
	 * Plays a sound effect asset specified by its filename.
	 *
	 * @param filename The filename of the sound effect asset to play.
	 * @param loops The number of times to loop the sound effect (0 for no loop).
	 * @param channel The audio channel to use for playback (0 for automatic channel assignment).
	 */
	void PlaySFX(std::string filename, int loops = 0, int channel = 0);

private:

	/**
	 * @brief Construct an AudioManager.
	 *
	 * Initializes an AudioManager instance.
	 */
	AudioManager();

	/**
	 * @brief Destroy the AudioManager.
	 *
	 * Cleans up resources associated with the AudioManager.
	 */
	~AudioManager();

};
#endif
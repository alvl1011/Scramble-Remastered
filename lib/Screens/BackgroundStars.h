#ifndef _BACKGROUNDSTARS_H
#define _BACKGROUNDSTARS_H

#include "Screens/StarLayer.h"

/**
 * @class BackgroundStars
 * @brief Manages the background star layers for a scrolling effect.
 *
 * The `BackgroundStars` class provides functionality to create and manage multiple layers of stars
 * to create a parallax scrolling background effect in a game or simulation.
 */
class BackgroundStars {

private:

	static BackgroundStars* bInstance;

	static const int LAYER_COUNT = 3;
	StarLayer* mLayers[LAYER_COUNT];

public:

	/**
	 * @brief Get the singleton instance of the BackgroundStars class.
	 * @return A pointer to the singleton instance.
	 *
	 * This function returns the singleton instance of the `BackgroundStars` class. If an instance
	 * does not exist, it will create one.
	 */
	static BackgroundStars* Instance();

	/**
	 * @brief Release the singleton instance of the BackgroundStars class.
	 *
	 * This function releases the singleton instance of the `BackgroundStars` class. It should be
	 * called when the class is no longer needed to free up resources.
	 */
	static void Release();

	/**
	 * @brief Initialize the background star layers.
	 *
	 * This function initializes the background star layers, creating and configuring them for the
	 * parallax scrolling effect.
	 */
	void Init();

	/**
	 * @brief Update the background star layers.
	 *
	 * This function updates the positions and behaviors of the background star layers, simulating
	 * the scrolling effect.
	 */
	void Update();

	/**
	 * @brief Render the background star layers.
	 *
	 * This function renders the background star layers to the screen, creating the visual
	 * parallax scrolling effect.
	 */
	void Render();

private:

	/**
	 * @brief Private constructor for the BackgroundStars class.
	 *
	 * The constructor is private to enforce the singleton pattern. Use `Instance()` to get
	 * the singleton instance.
	 */
	BackgroundStars();

	/**
	 * @brief Private destructor for the BackgroundStars class.
	 *
	 * The destructor is private to enforce the singleton pattern. Use `Release()` to release
	 * the singleton instance.
	 */
	~BackgroundStars();

};

#endif
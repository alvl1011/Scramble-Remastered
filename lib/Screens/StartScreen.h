#ifndef _STARTSCREEN_H
#define _STARTSCREEN_H

#include <vector>
#include "ECS.h"
#include "Components.h"
#include "BackgroundStars.h"
#include "MVC/PlayerController.h"
#include <sstream>
#include <iomanip>

/**
 * @class StartScreen
 * @brief Represents the game's start screen.
 *
 * The `StartScreen` class manages the game's start screen, including background stars, widgets,
 * and user interface elements. It provides functions for initialization, updating, rendering, and
 * controlling the start screen's appearance and behavior.
 */
class StartScreen {

private:

	static StartScreen* sInstance;
	BackgroundStars* stars;
	std::vector<Entity*> widgets;
	std::vector<Entity*> startScreenWidgets;
	std::vector<Entity*> gameWidgets;

public:

	/**
	 * @brief Get the singleton instance of the StartScreen.
	 * @return A pointer to the StartScreen instance.
	 */
	static StartScreen* Instance();

	/**
	 * @brief Release the StartScreen instance.
	 *
	 * This function releases the singleton instance of the StartScreen and cleans up resources.
	 */
	static void Release();

	/**
	 * @brief Initialize the StartScreen.
	 *
	 * This function initializes the StartScreen, creating background stars and setting up
	 * user interface elements.
	 */
	void Init();

	/**
	 * @brief Update the StartScreen.
	 *
	 * This function updates the state and behavior of the StartScreen, including widgets and stars.
	 */
	void Update();

	/**
	 * @brief Render the StartScreen.
	 *
	 * This function renders the StartScreen, including background stars and user interface elements.
	 */
	void Render();

	/**
	 * @brief Render the background stars.
	 *
	 * This function specifically renders the background stars to create a parallax scrolling effect.
	 */
	void RenderStars();

private:

	/**
	 * @brief Construct the StartScreen.
	 *
	 * This constructor creates an instance of the StartScreen.
	 */
	StartScreen();

	/**
	 * @brief Destroy the StartScreen.
	 *
	 * This destructor cleans up resources associated with the StartScreen.
	 */
	~StartScreen();
};

#endif

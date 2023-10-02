#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <vector>
#include "Timer.h"
#include "Vector2D.h"
#include <AudioManager.h>

class AssetManager;
class ColliderComponent;
class Entity;

/**
 * @class Game
 * @brief Main game class responsible for game initialization and management.
 *
 * The `Game` class is the core class that manages game initialization, event handling, game loop, rendering,
 * and other aspects of the game. It serves as the entry point for the game engine.
 */
class Game
{
public:

	/**
	* @brief Construct a Game object.
	*
	* Initializes a Game instance.
	*/
	Game();

	/**
	 * @brief Destructor for Game object.
	 *
	 * Cleans up resources associated with the Game instance.
	 */
	~Game();

	/**
	 * @brief Initialize the game.
	 *
	 * Initializes the game window, assets, and other components.
	 *
	 * @param title The title of the game window.
	 * @param x The x-coordinate of the game window.
	 * @param y The y-coordinate of the game window.
	 * @param width The width of the game window.
	 * @param height The height of the game window.
	 * @param full_screen Set to true for full-screen mode.
	 */
	void init(const char* title, int x, int y, int width, int height, bool full_screen);

	/**
	 * @brief Handle game events.
	 *
	 * Handles events such as user input, keyboard/mouse events, and window events.
	 */
	void handleEvents();

	/**
	 * @brief Update the game state.
	 *
	 * Updates the game logic, including player actions, physics, and game events.
	 */
	void update();

	/**
	 * @brief Check if the game is running.
	 *
	 * @return True if the game is running, false otherwise.
	 */
	bool running() { return isRunning; }

	/**
	 * @brief Render the game.
	 *
	 * Renders the game world and entities on the screen.
	 */
	void render();

	/**
	 * @brief Clean up resources and quit the game.
	 *
	 * Cleans up resources, releases memory, and exits the game.
	 */
	void clean();

	/**
	 * @brief Restart the game.
	 *
	 * Restarts the game, resetting game state and entities.
	 */
	void restart();

	/**
	 * @brief Get the player's score.
	 *
	 * @return The player's current score.
	 */
	static int getPlayerScore();

	/**
	 * @brief Set the player's score.
	 *
	 * @param score The player's score to set.
	 */
	static void setPlayerScore(int score);

	/**
	 * @brief Get the player's high score.
	 *
	 * @return The player's high score.
	 */
	static int getPlayerHighScore();

	/**
	 * @brief Get the player's fuel
	 *
	 * @return The player's fuel.
	 */
	static float getPlayerFuel();

	/**
	 * @brief Set the player's fuel
	 */
	static void setPlayerFuel(float fuel);

	/**
	 * @brief Get the player's remaining lives.
	 *
	 * @return The number of lives the player has remaining.
	 */
	static int getPlayerLives();

	/**
	 * @brief Get the entities' group from extern manager according to game group type.
	 *
	 * @return vector of entities.
	 */
	std::vector<Entity*>& getGroupFromManager(size_t groupname);

	/**
	 * @brief Validate game groups of entities.
	 *
	 * @return True if exists.
	 */
	bool validateGroup(size_t groupname) {
		switch (groupname)
		{
		case groups::groupMap:
		case groups::groupColliders:
		case groups::groupPlayers:
		case groups::groupEnemies:
		case groups::groupViews:
		case groups::groupLabels:
		case groups::groupStars:
			return true;
		default:
			return false;
		}
	}

	static int track;

	static std::vector<Vector2D> enemyCoordinates;
	static std::vector<Vector2D> buildingCoordinates;
	static Vector2D baseCoordinate;

	static SDL_Renderer* renderer;
	static SDL_Event event;
	static bool gameOver;
	static bool gameStarted;
	static bool victory;
	bool isRunning;
	static AssetManager* assets;
	static AudioManager* audioManager;
	Timer* timer;

	/**
	 * @brief Enumerations for grouping game entities.
	 */
	enum groups : std::size_t
	{
		groupMap,
		groupPlayers,
		groupColliders,
		groupEnemies,
		groupViews,
		groupLabels,
		groupStars
	};

private:

	int cnt = 0;
	SDL_Window* window;
};
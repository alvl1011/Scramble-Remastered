#ifndef _ROCKETENEMYCONTROLLER_H
#define _ROCKETENEMYCONTROLLER_H

#include "EnemyController.h"

/**
 * @class RocketEnemyController
 * @brief Represents a controller for managing and controlling rocket enemy entities.
 *
 * The `RocketEnemyController` class provides functionality for initializing, updating, and rendering
 * multiple rocket enemy entities in the game.
 */
class RocketEnemyController : public EnemyController {

private:

	std::vector<RocketEnemy*> enemies;

	static const int MAX_ENEMIES_COUNT = 10;


	/**
	 * @brief Initializes a collection of rocket enemy instances.
	 *
	 * This function initializes a number of rocket enemy instances up to the maximum allowed count.
	 */
	void initEnemies();

public:

	RocketEnemyController() {
		
	}

	/**
	* @brief Destructor for the RocketEnemyController class.
	*
	* Cleans up resources associated with rocket enemies.
	*/
	~RocketEnemyController() {
		for (auto& e : enemies) {
			delete e;
		}
	}

	/**
	 * @brief Respawns rocket enemies.
	 *
	 * This function clears the existing rocket enemy instances and reinitializes them.
	 */
	void respawn() {

		for (auto& e : enemies) {
			delete e;
		}

		enemies.clear();

		initEnemies();
	}

	/**
	 * @brief Initializes the RocketEnemyController.
	 */
	void init() override;

	/**
	 * @brief Updates the behavior and state of rocket enemy entities.
	 */
	void update() override;

	/**
	 * @brief Renders the rocket enemy entities on the screen.
	 */
	void render() override;

};

#endif
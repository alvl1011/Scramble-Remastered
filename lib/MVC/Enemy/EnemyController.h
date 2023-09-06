#pragma once

#include "Enemy.h"
#include "RocketEnemy.h"
#include "Components.h"
#include "Collision.h"
#include "MVC/Controller.h"

/**
 * @class EnemyController
 * @brief Represents a controller for managing and controlling enemy entities.
 *
 * The `EnemyController` class provides functionality for initializing, updating, and rendering
 * enemy entities of different types in the game.
 */
class EnemyController : Controller {
protected:

	Enemy* initEnemy(Enemy::Types type); ///< @brief Initializes an enemy of the specified type.
	void drawEnemy(); ///< @brief Renders the enemy.

private:

	Enemy* enemy;

public:

	/**
	* @brief Default constructor for the EnemyController class.
	*/
	EnemyController() = default;

	/**
	 * @brief Constructor for the EnemyController class with a specified enemy type.
	 * @param type The type of enemy to initialize and control.
	 */
	EnemyController(Enemy::Types type) {
		initEnemy(type);
	}

	/**
	 * @brief Renders the controlled enemy if it is not defeated.
	 */
	void render() override {
		if (enemy != NULL && !enemy->getIsDead()) {
			drawEnemy();
		}
	}

	/**
	 * @brief Gets the class of the currently controlled enemy.
	 * @return A pointer to the controlled enemy.
	 */
	Enemy* getEnemyClass() {
		return enemy;
	}

};
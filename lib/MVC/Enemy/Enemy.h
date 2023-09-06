#pragma once

#include "ECS.h"
#include "Components.h"
#include "EnemyView.h"
#include <string>

/**
 * @class Enemy
 * @brief Represents a base class for enemy entities in the game.
 *
 * The `Enemy` class serves as a base class for creating various types of enemy entities in the game.
 */
class Enemy {
protected:

	int score = 0;
	Entity* enemy;
	bool isDead;
	
public:

	/**
	 * @brief Enumeration of enemy types.
	 */
	enum Types : std::size_t
	{
		rocket
	};

	/**
	 * @brief Default constructor for the Enemy class.
	 */
	Enemy() = default;

	/**
	 * @brief Destructor for the Enemy class.
	 *
	 * Destroys the associated entity when the enemy is destroyed.
	 */
	~Enemy() {
		enemy->destroy();
	}

	/**
	 * @brief Initializes the enemy.
	 */
	virtual void init() {}

	/**
	 * @brief Updates the enemy's behavior and state.
	 */
	virtual void update() {}

	/**
	 * @brief Renders the enemy on the screen.
	 */
	virtual void draw() {}

	/**
	 * @brief Gets a pointer to the associated entity representing the enemy.
	 * @return A pointer to the enemy's entity.
	 */
	Entity* getEnemy() {
		return enemy;
	}

	/**
	 * @brief Sets the associated entity for the enemy.
	 * @param entity A pointer to the entity representing the enemy.
	 */
	void setEnemy(Entity* entity) {
		enemy = entity;
	}

	/**
	 * @brief Sets the score value awarded when the enemy is defeated.
	 * @param score The score value to set.
	 */
	void setScore(int score) {
		this->score = score;
	}

	/**
	 * @brief Gets the score value awarded when the enemy is defeated.
	 * @return The score value.
	 */
	int getScore() {
		return score;
	}

	/**
	 * @brief Sets the state of the enemy to indicate if it is defeated.
	 * @param value True if the enemy is defeated; otherwise, false.
	 */
	void setIsDead(bool value) {
		isDead = value;
	}

	/**
	 * @brief Checks if the enemy is currently defeated.
	 * @return True if the enemy is defeated; otherwise, false.
	 */
	bool getIsDead() {
		return isDead;
	}
};

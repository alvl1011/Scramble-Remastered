#pragma once

#include "ECS.h"
#include "Components.h"
#include "Collision.h"
#include "PlayerView.h"
#include <string>
#include <Windows.h>

/**
 * @class Player
 * @brief Represents a player entity in the game.
 *
 * The `Player` class represents a player entity with a name, lives, and scoring information.
 */
class Player {

private:

	Entity* entity;

	std::string name;
	bool is_dead = false;

	bool wasHit = false;

	int currentScore = 0;
	int highScore = 0;

public:

	int lives = 3;
	float fuel = 0.0f;

	/**
	 * @brief Constructor for the Player class.
	 * @param name The name of the player.
	 * @param lives The initial number of lives for the player.
	 * @param highScore The initial high score for the player.
	 */
	Player(std::string name, int lives, int highScore);

	/**
	 * @brief Destructor for the Player class.
	 */
	~Player();

	/**
	 * @brief Initializes the player entity.
	 */
	void init();

	/**
	 * @brief Updates the behavior and state of the player.
	 */
	void update();

	/**
	 * @brief Updates the player's current score.
	 */
	void updateCurrentScore();

	/**
	 * @brief Updates collision-related behaviors for the player.
	 */
	void updateCollision();

	/**
	 * @brief Gets the entity representing the player.
	 * @return A pointer to the player's entity.
	 */
	Entity* getPlayer();

	/**
	 * @brief Gets the name of the player.
	 * @return The player's name.
	 */
	std::string getName() {
		return name;
	}

	/**
	 * @brief Checks if the player is dead.
	 * @return True if the player is dead, false otherwise.
	 */
	bool getIsDead() {
		return is_dead;
	}

	/**
	 * @brief Sets the player's death state.
	 * @param value True to indicate the player is dead, false otherwise.
	 */
	void setIsDead(bool value) {
		is_dead = value;
	}

	/**
	 * @brief Gets the current score of the player.
	 * @return The current score.
	 */
	int getCurrentScore() {
		return currentScore;
	}

	/**
	 * @brief Sets the current score of the player.
	 * @param score The new current score.
	 */
	void setCurrentScore(int score) {
		currentScore = score;
	}

	/**
	 * @brief Sets the high score achieved by the player.
	 * @param score The new high score.
	 */
	void setHighScore(int score) {
		highScore = score;
	}

	/**
	* @brief Gets the high score achieved by the player.
	* @return The high score.
	*/
	int getHighScore() {
		return highScore;
	}
};
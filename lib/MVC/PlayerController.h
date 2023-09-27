#pragma once

#include "Player.h"
#include "MVC/Controller.h"
#include "Components.h"
#include "Collision.h"
#include <sstream>
#include "AnimatedView.h"
#include "Bullet.h"
#include "RocketBullet.h"

extern Manager manager;

/**
 * @class PlayerController
 * @brief Manages player actions and interactions in the game.
 *
 * The `PlayerController` class is responsible for managing the player's actions, including movement, firing, and handling bullets.
 */
class PlayerController : Controller {
private:

	Player* player;

	static const int MAX_BULLETS = 5;
	Bullet* mBullets[MAX_BULLETS];

	static const int MAX_ROCKET_BULLETS = 2;
	RocketBullet* mRocketBullets[MAX_ROCKET_BULLETS];
	
	bool wasHit = false;

	/**
	 * @brief Initializes the player instance with the specified name, lives, and high score.
	 * @param name The name of the player.
	 * @param lives The initial number of lives for the player.
	 * @param highScore The initial high score for the player.
	 * @return A pointer to the initialized player.
	 */
	Player* initPlayer(std::string name, int lives, int highScore);

	/**
	 * @brief Draws the player on the screen.
	 */
	void drawPlayer();

	/**
	 * @brief Handles firing bullets and rocket bullets.
	 */
	void HandleFiring();

public:

	/**
	 * @brief Default constructor for the PlayerController class.
	 */
	PlayerController() = default;

	/**
	 * @brief Constructor for the PlayerController class with a specified player name.
	 * @param name The name of the player.
	 */
	PlayerController(std::string name) {
		initPlayer(name, 3, 0);
	}

	/**
	 * @brief Destructor for the PlayerController class.
	 *
	 * Cleans up resources associated with bullets and rocket bullets.
	 */
	~PlayerController() {
		for (int i = 0; i < MAX_BULLETS; i++) {
			delete mBullets[i];
			mBullets[i] = NULL;
		}

		for (int i = 0; i < MAX_ROCKET_BULLETS; i++) {
			delete mRocketBullets[i];
			mRocketBullets[i] = NULL;
		}
	}

	/**
	 * @brief Respawns the player with the original number of lives and high score.
	 */
	void respawn() {
		std::string name = player->getName();
		int lives = Game::gameStarted ? player->lives : 3;
		int highScore = player->getHighScore();
		delete player;
		player = NULL;

		initPlayer(name, lives, highScore);
	}

	/**
	 * @brief Updates the player's behavior and interactions.
	 */
	void update() override {
		if (player->getPlayer()->isActive()) {
			player->update();

			HandleFiring();

			for (int i = 0; i < MAX_BULLETS; i++) {
				mBullets[i]->Update();
			}

			for (int i = 0; i < MAX_ROCKET_BULLETS; i++) {
				mRocketBullets[i]->update();
			}
		}
	}

	/**
	 * @brief Renders the player, bullets, and rocket bullets on the screen.
	 */
	void render() override {
		drawPlayer();

		for (int i = 0; i < MAX_BULLETS; i++) {
			mBullets[i]->Render();
		}

		for (int i = 0; i < MAX_ROCKET_BULLETS; i++) {
			mRocketBullets[i]->render();
		}
	}

	/**
	 * @brief Gets the player instance being controlled.
	 * @return A pointer to the player.
	 */
	Player* getPlayer() {
		return player;
	}
};
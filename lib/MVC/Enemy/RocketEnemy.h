#pragma once

#include "ECS.h"
#include "Components.h"
#include "Collision.h"
#include "Enemy.h"
#include "MVC/Enemy/RocketEnemyView.h"

/**
 * @class RocketEnemy
 * @brief Represents a specific type of enemy entity called a rocket enemy.
 *
 * The `RocketEnemy` class is a derived class of the `Enemy` class and represents a specific
 * type of enemy entity with unique behaviors and characteristics.
 */
class RocketEnemy : public Enemy {
private:

	Types type = Types::rocket;

	/**
	 * @brief Updates the collider of the rocket enemy.
	 *
	 * This function handles the updates to the collision boundaries of the rocket enemy.
	 */
	void updateCollider();

	/**
	 * @brief Updates the trigger behavior of the rocket enemy.
	 *
	 * This function handles the updates to the trigger zone behavior of the rocket enemy.
	 */
	void updateTrigger();

	/**
	 * @brief Updates the animations of the rocket enemy.
	 *
	 * This function handles the updates to the animations of the rocket enemy.
	 */
	void updateAnimations();

public:

	/**
	 * @brief Initializes the rocket enemy at a specified position.
	 * @param x The initial X-coordinate of the rocket enemy.
	 * @param y The initial Y-coordinate of the rocket enemy.
	 */
	void initEnemy(float x, float y);

	/**
	 * @brief Updates the behavior and state of the rocket enemy.
	 */
	void update() override;

	/**
	 * @brief Renders the rocket enemy on the screen.
	 */
	void draw() override;
};
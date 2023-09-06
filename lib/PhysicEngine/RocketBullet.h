#ifndef _ROCKETBULLET_H
#define _ROCKETBULLET_H

#include "Timer.h"
#include "ECS.h"
#include "Vector2D.h"
#include "TransformComponent.h"
#include "AnimatedView.h"
#include "Collision.h"

/**
 * @class RocketBullet
 * @brief Represents a rocket projectile fired from a weapon.
 *
 * The `RocketBullet` class models a rocket projectile fired from a weapon. It manages the rocket's position,
 * movement, collision, and rendering.
 */
class RocketBullet {

private:

	const int OFFSCREEN_BUFFER = 10;

	Timer* mTimer;

	float mSpeed;

	Entity* rocket;

	bool isActive;

public:

	RocketBullet();
	~RocketBullet();

	/**
	 * @brief Fires the rocket from a specified position.
	 * @param position The starting position of the rocket.
	 *
	 * This method initiates the firing of the rocket from the given position.
	 */
	void Fire(Vector2D position);

	/**
	 * @brief Reloads the rocket, making it inactive.
	 *
	 * This method resets the rocket, making it inactive and ready to be fired again.
	 */
	void Reload();

	/**
	 * @brief Updates the rocket's position and checks for collisions.
	 *
	 * This method updates the rocket's position based on its speed and checks for collisions with other entities.
	 */
	void update();

	/**
	* @brief Renders the rocket.
	*
	* This method renders the rocket entity if it is currently active.
	*/
	void render();

	/**
	 * @brief Gets the entity representing the rocket.
	 * @return A pointer to the entity representing the rocket.
	 */
	Entity* getRocket() {
		return rocket;
	}

	/**
	 * @brief Checks if the rocket is currently active (in-flight).
	 * @return `true` if the rocket is active, `false` otherwise.
	 */
	bool getIsActive() {
		return isActive;
	}

	/**
	 * @brief Sets the activity state of the rocket.
	 * @param value `true` to activate the rocket, `false` to deactivate it.
	 *
	 * This method sets the activity state of the rocket. If activated, the rocket is added to collision groups.
	 */
	void setIsActive(bool value) {

		if (value && !rocket->hasGroup(Game::groupColliders)) {
			rocket->addGroup(Game::groupColliders);
		}

		isActive = value;
	}
};
#endif
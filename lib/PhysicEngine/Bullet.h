#ifndef _BULLET_H
#define _BULLET_H

#include "Timer.h"
#include "ECS.h"
#include "Vector2D.h"
#include "SpriteComponent.h"
#include "TransformComponent.h"
#include "Collision.h"

/**
 * @class Bullet
 * @brief Represents a projectile fired from a weapon.
 *
 * The `Bullet` class models a projectile fired from a weapon. It manages the bullet's position,
 * movement, collision, and rendering.
 */
class Bullet {

private:

	const int OFFSCREEN_BUFFER = 10;

	Timer* mTimer;

	float mSpeed;

	Entity* bullet;

	bool isActive;

public:

	Bullet();
	~Bullet();

	/**
	* @brief Fires the bullet from a specified position.
	* @param position The starting position of the bullet.
	*
	* This method initiates the firing of the bullet from the given position.
	*/
	void Fire(Vector2D position);

	/**
	 * @brief Reloads the bullet, making it inactive.
	 *
	 * This method resets the bullet, making it inactive and ready to be fired again.
	 */
	void Reload();

	/**
	 * @brief Updates the bullet's position and checks for collisions.
	 *
	 * This method updates the bullet's position based on its speed and checks for collisions with other entities.
	 */
	void Update();

	/**
	 * @brief Renders the bullet.
	 *
	 * This method renders the bullet entity if it is currently active.
	 */
	void Render();

	/**
	 * @brief Updates collision-related properties of the bullet.
	 *
	 * This method updates collision-related properties of the bullet, such as adding it to collision groups.
	 */
	void UpdateCollission();

	/**
	 * @brief Gets the entity representing the bullet.
	 * @return A pointer to the entity representing the bullet.
	 */
	Entity* getBullet() {
		return bullet;
	}

	/**
	 * @brief Checks if the bullet is currently active (in-flight).
	 * @return `true` if the bullet is active, `false` otherwise.
	 */
	bool getIsActive() {
		return isActive;
	}

	/**
	 * @brief Sets the activity state of the bullet.
	 * @param value `true` to activate the bullet, `false` to deactivate it.
	 *
	 * This method sets the activity state of the bullet. If activated, the bullet is added to collision groups.
	 */
	void setIsActive(bool value) {

		if (value && !bullet->hasGroup(Game::groupColliders)) {
			bullet->addGroup(Game::groupColliders);
		}

		isActive = value;

	}

};

#endif
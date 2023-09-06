#pragma once

#include "Vector2D.h"

/**
 * @class TransformComponent
 * @brief Represents a component that manages an entity's position and velocity in 2D space.
 *
 * The `TransformComponent` class is responsible for handling an entity's position, velocity, and size.
 */
class TransformComponent : public Component {

public:

	Vector2D position;
	Vector2D velocity;

	int height = 32;
	int width = 32;
	int scale = 1;

	int speed = 3;

	/**
	 * @brief Default constructor for TransformComponent, initializes the position to (0, 0).
	 */
	TransformComponent() {
		position.Zero();
	}

	/**
	 * @brief Constructor for TransformComponent with a specified scale.
	 * @param sc The scale factor for the entity.
	 */
	TransformComponent(int sc) {
		position.x = 400;
		position.y = 320;
		scale = sc;
	}

	/**
	* @brief Constructor for TransformComponent with specified initial coordinates.
	* @param x The initial X-coordinate.
	* @param y The initial Y-coordinate.
	*/
	TransformComponent(float x, float y) {
		position.x = x;
		position.y = y;
	}

	/**
	* @brief Constructor for TransformComponent with specified coordinates, size, and scale.
	* @param x The initial X-coordinate.
	* @param y The initial Y-coordinate.
	* @param h The height of the entity.
	* @param w The width of the entity.
	* @param sc The scale factor for the entity.
	*/
	TransformComponent(float x, float y, int h, int w, int sc) {
		position.x = x;
		position.y = y;
		height = h;
		width = w;
		scale = sc;
	}

	/**
	 * @brief Constructor for TransformComponent with specified coordinates, size, scale, and speed.
	 * @param x The initial X-coordinate.
	 * @param y The initial Y-coordinate.
	 * @param h The height of the entity.
	 * @param w The width of the entity.
	 * @param sc The scale factor for the entity.
	 * @param spd The movement speed of the entity.
	 */
	TransformComponent(float x, float y, int h, int w, int sc, int speed) {
		position.x = x;
		position.y = y;
		height = h;
		width = w;
		scale = sc;
		speed = speed;
	}

	/**
	 * @brief Initializes the transform component by resetting the velocity.
	 */
	void init() override {
		velocity.Zero();
	}

	/**
	 * @brief Updates the entity's position based on its velocity and speed.
	 */
	void update() override {
		position.x += velocity.x * speed;
		position.y += velocity.y * speed;
	}
};
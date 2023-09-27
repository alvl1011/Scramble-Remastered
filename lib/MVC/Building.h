#ifndef _BUILDING_H
#define _BUILDING_H

#include "ECS.h"
#include "Components.h"
#include "AnimatedView.h"
#include "Collision.h"

/**
 * @class Building
 * @brief Represents a building entity in the game.
 *
 * The `Building` class represents a building entity with a specific location, score value, and state.
 */
class Building {
private:

	int scores;

	bool is_base = false;
	bool is_fuel = false;
	bool destroyed;

	Entity* entity;

	/**
	 * @brief Updates the collider of the building.
	 *
	 * This function handles the updates to the collision boundaries of the building.
	 */
	void updateCollider();

	/**
	 * @brief Updates the animations of the building.
	 *
	 * This function handles the updates to the animations of the building, if applicable.
	 */
	void updateAnimations();

public:

	/**
	* @brief Constructor for the Building class.
	* @param x The X-coordinate of the building's position.
	* @param y The Y-coordinate of the building's position.
	* @param scores The score value associated with the building.
	* @param is_base Indicates whether the building is a base (default is false).
	* @param is_fuel Indicates whether the building is a fuel building (default is false).
	*/
	Building(float x, float y, int scores, bool is_base, bool is_fuel);

	/**
	 * @brief Destructor for the Building class.
	 *
	 * Cleans up resources associated with the building.
	 */
	~Building();

	/**
	 * @brief Updates the behavior and state of the building.
	 */
	void update();

	/**
	 * @brief Renders the building on the screen.
	 */
	void draw();

	/**
	* @brief Gets the score value associated with the building.
	* @return The score value.
	*/
	int getScores() {
		return scores;
	}

	/**
	* @brief Gets the entity of building.
	* @return entity.
	*/
	Entity* getBuilding() {
		return entity;
	}

};
#endif

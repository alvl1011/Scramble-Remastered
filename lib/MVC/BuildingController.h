#ifndef _BUILDINGCONTROLLER_H
#define _BUILDINGCONTROLLER_H

#include "Building.h"

/**
 * @class BuildingController
 * @brief Represents a controller for managing and controlling building entities.
 *
 * The `BuildingController` class provides functionality for initializing, updating, and rendering
 * multiple building entities in the game.
 */
class BuildingController {

private:

	std::vector<Building*> buildings;

	static const int MAX_BUILDINGS_COUNT = 2;

	/**
	 * @brief Initializes a collection of building instances.
	 *
	 * This function initializes a number of building instances up to the maximum allowed count.
	 */
	void initBuildings();

public:

	/**
	 * @brief Default constructor for the BuildingController class.
	 */
	BuildingController() {}

	/**
	 * @brief Destructor for the BuildingController class.
	 *
	 * Cleans up resources associated with building entities.
	 */
	~BuildingController() {
		for (auto& b : buildings) {
			delete b;
		}
	}

	/**
     * @brief Respawns building entities.
     * 
     * This function clears the existing building instances and reinitializes them.
     */
	void respawn() {

		for (auto& b : buildings) {
			delete b;
		}

		buildings.clear();

		initBuildings();
	}

	/**
	* @brief Initializes the BuildingController.
	*/
	void init();

	/**
	 * @brief Updates the behavior and state of building entities.
	 */
	void update();

	/**
	 * @brief Renders the building entities on the screen.
	 */
	void render();

};
#endif
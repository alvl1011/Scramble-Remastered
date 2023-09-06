#pragma once

#include "SDL.h"

class ColliderComponent;

/**
 * @class Collision
 * @brief Provides collision detection methods.
 *
 * The `Collision` class contains static methods for detecting collisions between objects,
 * such as SDL_Rectangles or ColliderComponents.
 */
class Collision {

public:

    /**
     * @brief Checks for collision between two SDL_Rectangles.
     * @param recA The first SDL_Rectangle to check.
     * @param recB The second SDL_Rectangle to check.
     * @return `true` if the rectangles intersect, `false` otherwise.
     *
     * This method determines whether two SDL_Rectangles intersect.
     */
	static bool AABB(const SDL_Rect& recA, const SDL_Rect& recB);

    /**
    * @brief Checks for collision between two ColliderComponents.
    * @param colA The first ColliderComponent to check.
    * @param colB The second ColliderComponent to check.
    * @return `true` if the ColliderComponents intersect, `false` otherwise.
    *
    * This method determines whether two ColliderComponents intersect.
    */
	static bool AABB(const ColliderComponent& colA, const ColliderComponent& colB);
};

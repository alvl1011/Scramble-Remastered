#ifndef _STAR_H
#define _STAR_H

#include "Timer.h"
#include "ECS.h"
#include "TransformComponent.h"
#include "SpriteComponent.h"

/**
 * @class Star
 * @brief Represents a star object in the background.
 *
 * The `Star` class represents a single star object that is part of the background in the parallax
 * scrolling effect. Stars can flicker and move to create a dynamic background.
 */
class Star {

private:

	static bool sScroll;

	Entity* star;
	Timer* mTimer;
	
	bool mVisible;
	float mFlickerTimer;
	float mFlickerSpeed;

	float mScrollSpeed;

public:

	/**
	 * @brief Set whether stars should scroll.
	 * @param b True to enable scrolling, false to disable.
	 *
	 * This static function sets a flag to control whether stars in the background should scroll
	 * with the parallax effect.
	 */
	static void Scroll(bool b);

	/**
	 * @brief Construct a star object.
	 * @param layer The layer to which the star belongs.
	 *
	 * This constructor creates a star object and associates it with a specific layer.
	 * @see StarLayer
	 */
	Star(int layer);

	/**
	 * @brief Destroy the star object.
	 *
	 * This destructor cleans up resources associated with the star object.
	 */
	~Star();

	/**
	* @brief Initialize the star object.
	*
	* This function initializes the star object, setting its initial state and properties.
	*/
	void init();

	/**
	 * @brief Update the star object.
	 *
	 * This function updates the state and behavior of the star object, including flickering and
	 * scrolling.
	 */
	void update();

	/**
	 * @brief Render the star object.
	 *
	 * This function renders the star object to the screen, making it visible if it should be
	 * displayed.
	 */
	void draw();

private:

	/**
	 * @brief Scroll the star.
	 *
	 * This private function scrolls the star based on the scrolling flag and the scroll speed.
	 */
	void ScrollStar();
};

#endif
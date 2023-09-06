#ifndef _STARLAYER_H
#define _STARLAYER_H

#include "Screens/Star.h"

/**
 * @class StarLayer
 * @brief Represents a layer of stars in the background.
 *
 * The `StarLayer` class represents a layer of stars that is part of the background in the parallax
 * scrolling effect. Each layer can have its own set of stars with unique properties.
 */
class StarLayer {

private:

	static const int STAR_COUNT = 30;
	Star* mStars[STAR_COUNT];

public:

	/**
	 * @brief Construct a star layer.
	 * @param layer The layer index for this star layer.
	 *
	 * This constructor creates a star layer with a specific layer index. The layer index
	 * determines its position in the parallax scrolling effect.
	 */
	StarLayer(int layer);

	/**
	* @brief Destroy the star layer.
	*
	* This destructor cleans up resources associated with the star layer and its stars.
	*/
	~StarLayer();

	/**
	 * @brief Update the star layer.
	 *
	 * This function updates the state and behavior of all stars in the layer.
	 */
	void Update();

	/**
	 * @brief Render the star layer.
	 *
	 * This function renders all stars in the layer, making them visible on the screen.
	 */
	void Render();

};

#endif

#ifndef _ANIMATED_VIEW_H
#define _ANIMATED_VIEW_H

#include "SpriteComponent.h"
#include "Timer.h"

/**
 * @class AnimatedView
 * @brief Extends SpriteComponent to manage animated sprite views.
 */
class AnimatedView : public SpriteComponent {
public:

	/**
	 * @enum WRAP_MODE
	 * @brief Enumeration for animation wrap modes.
	 *        - ONCE: Animation plays only once.
	 *        - LOOP: Animation loops continuously.
	 */
	enum WRAP_MODE {
		ONCE = 0,
		LOOP = 1
	};
	
private:

	Timer* mTimer; ///< @brief Pointer to a Timer object for animation timing. Singleton instance.

	int mStartX, mStartY; ///< @brief Initial X and Y coordinates of the sprite.

	float mAnimTimer; ///< @brief Current animation timer for frame timing.
	float mAnimSpeed; ///< @brief Animation speed for frame advancement.
	float mTimePerFrame; ///< @brief Time duration per animation frame.

	int mFrameCount; ///< @brief Total number of frames in the animation.

	WRAP_MODE wrapMode; ///< @brief Current animation wrap mode (ONCE or LOOP).

	bool mAnimDone; ///< @brief Flag indicating whether the animation has finished.

public:

	AnimatedView(std::string asset, int startX, int frameCount, float animSpeed);
	~AnimatedView();

	/**
	 * @brief Sets the animation wrap mode.
	 * @param mode The desired animation wrap mode (ONCE or LOOP).
	 */
	void WrapMode(WRAP_MODE mode);

	/**
	 * @brief Sets animation parameters and wrap mode.
	 * @param startY The Y-coordinate of the starting position of the sprite.
	 * @param speed The animation speed for frame advancement.
	 * @param mode The desired animation wrap mode (ONCE or LOOP).
	 */
	void setAnimation(int startY, float speed, WRAP_MODE mode) {
		mStartY = startY;
		mAnimSpeed = speed;
		WrapMode(mode);
	}

	/**
	 * @brief Resets the animation to its initial state.
	 */
	void ResetAnimation();

	/**
	 * @brief Checks if the animation is currently playing.
	 * @return True if the animation is playing; otherwise, false.
	 */
	bool IsAnimating();

	/**
	 * @brief Updates the animated view, advancing animation frames based on parameters.
	 */
	void Update();
};
#endif

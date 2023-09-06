#pragma once

/**
 * @struct Animation
 * @brief Represents an animation sequence.
 *
 * The `Animation` struct defines the properties of an animation sequence, including its index, the number of frames,
 * and the speed at which it should be played.
 */
struct Animation {

	int index;
	int frames;
	int speed;

	/**
	 * @brief Default constructor for the Animation struct.
	 */
	Animation() {}

	/**
	 * @brief Constructor for the Animation struct with specified parameters.
	 * @param i The index or identifier of the animation.
	 * @param f The total number of frames in the animation sequence.
	 * @param s The speed at which the animation should be played.
	 */
	Animation(int i, int f, int s) {
		index = i;
		frames = f;
		speed = s;
	}
};
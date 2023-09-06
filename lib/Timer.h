#ifndef _TIMER_H
#define _TIMER_H

#include "SDL.h"

/**
 * @class Timer
 * @brief A utility class for tracking time and managing frame rate.
 *
 * The `Timer` class provides functionality for measuring time, calculating the delta time, and managing time scale.
 */
class Timer {
private:

	static Timer* tInstance;

	unsigned int startTicks;
	unsigned int elapsedTicks;
	float deltaTime;
	float timeScale;

public:

	/// @brief The desired frame rate for the application.
	const static int FRAME_RATE = 60;

	/**
	 * @brief Get a pointer to the Timer instance.
	 *
	 * If a Timer instance does not exist, it will be created.
	 *
	 * @return A pointer to the Timer instance.
	 */
	static Timer* Instance();

	/**
	 * @brief Release the Timer instance.
	 *
	 * Deletes the Timer instance and releases associated resources.
	 */
	static void Release();

	/**
	 * @brief Reset the timer.
	 *
	 * Resets the timer to its initial state.
	 */
	void Reset();

	/**
	 * @brief Get the delta time between frames.
	 *
	 * Calculates and returns the time in seconds between frames.
	 *
	 * @return The delta time between frames.
	 */
	float DeltaTime();

	/**
	 * @brief Set the time scale.
	 *
	 * Adjusts the time scale to control the speed of time.
	 *
	 * @param t The desired time scale factor.
	 */
	void TimeScale(float t);

	/**
	 * @brief Get the current time scale.
	 *
	 * Returns the current time scale factor.
	 *
	 * @return The current time scale factor.
	 */
	float TimeScale();

	/**
	 * @brief Update the timer.
	 *
	 * Updates the timer's internal state, including elapsed time and delta time.
	 */
	void Update();

private:

	/**
	 * @brief Construct a Timer object.
	 *
	 * Initializes a Timer instance with default values.
	 */
	Timer();

	/**
	 * @brief Destructor for Timer object.
	 *
	 * Cleans up resources associated with the Timer instance.
	 */
	~Timer();
};

#endif

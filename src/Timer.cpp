#include "Timer.h"

Timer* Timer::tInstance = NULL;

Timer* Timer::Instance() {

	if (tInstance == NULL) {
		tInstance = new Timer();
	}

	return tInstance;
}

void Timer::Release() {

	delete tInstance;
	tInstance = NULL;
}

Timer::Timer() {
	Reset();
	timeScale = 1.0f;

}

Timer::~Timer() {

}

void Timer::Reset() {
	startTicks = SDL_GetTicks();
	elapsedTicks = 0;
	deltaTime = 0.0f;
}

float Timer::DeltaTime() {
	return deltaTime;
}

void Timer::TimeScale(float t) {
	timeScale = t;
}

float Timer::TimeScale() {
	return timeScale;
}

void Timer::Update() {
	elapsedTicks = SDL_GetTicks() - startTicks;
	// conversion in milliseconds
	deltaTime = elapsedTicks * 0.001f;
}
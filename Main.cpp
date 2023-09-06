#include "SDL.h"
#include "Game.h"
#include "Timer.h"

Game* game = nullptr;

int main(int argc, char* argv[]) {

	const int FPS = 60;
	const int frame_delay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	game = new Game();
	game->init("Scramble *remastered*", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 670, false);
	while (game->running()) {

		game->timer->Update();

		frameStart = SDL_GetTicks();

		game->handleEvents();
		game->update();

		if (game->timer->DeltaTime() >= 1.0f / Timer::FRAME_RATE) {

			game->render();

			game->timer->Reset();
		}
		
		frameTime = SDL_GetTicks() - frameStart;

		if (frame_delay > frameTime) {
			SDL_Delay(frame_delay - frameTime);
		}

		
	}

	game->clean();

	return 0;
}
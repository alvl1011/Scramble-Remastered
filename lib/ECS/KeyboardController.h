#pragma once

#include "Game.h"
#include "ECS.h"
#include "Components.h"

/**
 * @class KeyboardController
 * @brief Handles keyboard input to control the movement of an entity.
 */
class KeyboardController : public Component {

public:

	TransformComponent* transform; ///< @brief Pointer to the associated TransformComponent.

	/**
	 * @brief Initializes the KeyboardController by obtaining a reference to the TransformComponent.
	 */
	void init() override {

		transform = &entity->getComponent<TransformComponent>();
	}

	/**
	* @brief Updates the entity's velocity based on keyboard input.
	*        Handles movement commands (W, A, S, D) and stops movement when the game is over or won.
	*/
	void update() override {
		if (!Game::gameOver && !Game::victory) {
			if (Game::event.type == SDL_KEYDOWN) {
				switch (Game::event.key.keysym.sym) {
				case SDLK_w:
					transform->velocity.y = -1;
					break;
				case SDLK_a:
					transform->velocity.x = -1;
					break;
				case SDLK_s:
					transform->velocity.y = 1;
					break;
				case SDLK_d:
					transform->velocity.x = 1;
					break;
				default:
					break;
				}
			}

			if (Game::event.type == SDL_KEYUP) {
				switch (Game::event.key.keysym.sym) {
				case SDLK_w:
					transform->velocity.y = 0;
					break;
				case SDLK_s:
					transform->velocity.y = 0;
					break;
				case SDLK_a:
					transform->velocity.x = 0;
					break;
				case SDLK_d:
					transform->velocity.x = 0;
					break;
				default:
					break;
				}
			}
		}
		else {
			transform->velocity.x = 0;
			transform->velocity.y = 0;
		}
	}
};
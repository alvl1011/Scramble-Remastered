#pragma once

#include <string>
#include "SDL.h"
#include "ECS.h"
#include "Components.h"
#include "TextureManager.h"

/**
 * @class TriggerComponent
 * @brief Represents a component responsible for defining trigger zones within the game.
 *
 * The `TriggerComponent` class is used to create trigger zones that can activate certain
 * actions or behaviors when entered by game entities.
 */
class TriggerComponent : public Component {
public:

	SDL_Rect trigger;
	
	SDL_Texture* tex;
	SDL_Rect srcR, destR;

	TransformComponent* transform;

	/**
	 * @brief Default constructor for TriggerComponent.
	 */
	TriggerComponent() = default;

	/**
	* @brief Constructor for TriggerComponent with specified position and size.
	* @param xpos The X-coordinate of the trigger zone.
	* @param ypos The Y-coordinate of the trigger zone.
	* @param sizeW The width of the trigger zone.
	* @param sizeH The height of the trigger zone.
	*/
	TriggerComponent(int xpos, int ypos, int sizeW, int sizeH) {
		trigger.x = xpos;
		trigger.y = ypos;
		trigger.w = sizeW;
		trigger.h = sizeH;
	}

	/**
	 * @brief Initializes the trigger component.
	 *
	 * This function should be called after attaching the component to an entity.
	 */
	void init() override {
		if (!entity->hasComponent<TransformComponent>()) {
			entity->addComponent<TransformComponent>();
		}

		transform = &entity->getComponent<TransformComponent>();

		tex = TextureManager::LoadTexture("assets/collider.png");
		srcR = { 0, 0, 32, 32 };
		destR = { trigger.x, trigger.y, trigger.w, trigger.h };
	}

	/**
	 * @brief Updates the trigger zone.
	 *
	 * This function can be used to update the trigger zone's behavior, such as movement.
	 */
	void update() override {


		if (!Game::gameOver) {
			destR.x += (-2);
			trigger.x += (-2);
		}
	}

	/* FOR DEVELOPMENT*/
	//void draw() override {
	//	TextureManager::Draw(tex, srcR, destR, SDL_FLIP_NONE);
	//}

};
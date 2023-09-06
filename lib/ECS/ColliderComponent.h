#pragma once

#include <string>
#include "SDL.h"
#include "ECS.h"
#include "Components.h"
#include "TextureManager.h"

/**
 * @class ColliderComponent
 * @brief Extends Component, manages collision detection and behavior for Entities.
 */
class ColliderComponent : public Component {

public:

	SDL_Rect collider, initCollider; ///< @brief collider - The collision rectangle. initCollider - The initial collision rectangle.
	std::string tag; ///< @brief A tag to identify the collider's purpose.

	SDL_Texture* tex; ///< @brief The texture associated with the collider.
	SDL_Rect srcR, destR, initR; ///< @brief Source and destination rectangles for rendering.

	TransformComponent* transform; ///< @brief A pointer to the entity's transform component.

	/**
	 * @brief Default constructor.
	 */
	ColliderComponent() = default;

	/**
	* @brief Constructor with a specified tag.
	* @param t The tag to identify the collider's purpose.
	*/
	ColliderComponent(std::string t) {
		tag = t;
	}

	/**
	* @brief Constructor with a specified tag, position, and size.
	* @param t The tag to identify the collider's purpose.
	* @param xpos The X-coordinate of the collider's position.
	* @param ypos The Y-coordinate of the collider's position.
	* @param size The size (width and height) of the collider.
	*/
	ColliderComponent(std::string t, int xpos, int ypos, int size) {
		tag = t;
		collider.x = xpos;
		collider.y = ypos;
		collider.h = size;
		collider.w = size;

		initCollider.x = xpos;
		initCollider.y = ypos;
		initCollider.h = size;
		initCollider.w = size;
	}

	/**
	 * @brief Constructor with a specified tag, position, and size (width and height).
	 * @param t The tag to identify the collider's purpose.
	 * @param xpos The X-coordinate of the collider's position.
	 * @param ypos The Y-coordinate of the collider's position.
	 * @param sizeW The width of the collider.
	 * @param sizeH The height of the collider.
	 */
	ColliderComponent(std::string t, int xpos, int ypos, int sizeW, int sizeH) {
		tag = t;
		collider.x = xpos;
		collider.y = ypos;
		collider.h = sizeH;
		collider.w = sizeW;

		initCollider.x = xpos;
		initCollider.y = ypos;
		initCollider.h = sizeH;
		initCollider.w = sizeW;

	}

	/**
	 * @brief Initializes the collider component.
	 * This function should be called after attaching the component to an entity.
	 */
	void init() override {

		if (!entity->hasComponent<TransformComponent>()) {
			entity->addComponent<TransformComponent>();
		}

		transform = &entity->getComponent<TransformComponent>();

		tex = TextureManager::LoadTexture("assets/collider.png");
		srcR = { 0, 0, 32, 32 };
		if (tag == "terrain") {
			destR = { collider.x, collider.y + 20, collider.w, collider.h };
		}
		else {
			destR = { collider.x, collider.y, collider.w, collider.h };
		}

		initR = destR;
		initCollider = collider;
	}

	/**
	 * @brief Updates the collider's position and behavior.
	 */
	void update() override {

		if (tag != "terrain" && tag != "trigger") {
			collider.x = static_cast<int>(transform->position.x);
			collider.y = static_cast<int>(transform->position.y);
			if (tag == "player") {
				collider.w = transform->width * 1;
				collider.h = transform->height * 1;
			}
			else {
				collider.w = transform->width * transform->scale;
				collider.h = transform->height * transform->scale;
			}
		}

		if (!Game::gameOver) {
			destR.x += (-2);
			collider.x += (-2);
		}
	}

	/**
	 * @brief Draws the collider (for debug purpose).
	 * Use TextureManager::Draw to render the collider if needed.
	 */
	void draw() override {
		// TextureManager::Draw(tex, srcR, destR, SDL_FLIP_NONE);
	}

private:

};
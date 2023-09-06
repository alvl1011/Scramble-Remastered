#pragma once

#include "ECS.h"
#include "TransformComponent.h"
#include "SpriteComponent.h"
#include "SDL.h"
#include "AssetManager.h"

/**
 * @class TileComponent
 * @brief Represents a component for rendering individual tiles on the screen.
 *
 * The `TileComponent` class is responsible for rendering individual tiles using SDL.
 */
class TileComponent : public Component {

public:

	SDL_Texture* texture;
	SDL_Rect srcRect, destRect, initRect;

	/**
	* @brief Default constructor for TileComponent.
	*/
	TileComponent() = default;

	/**
	 * @brief Destructor for TileComponent, responsible for cleaning up the texture.
	 */
	~TileComponent() {
		SDL_DestroyTexture(texture);
	}

	/**
	 * @brief Constructor for TileComponent with specified parameters.
	 * @param srcX The X-coordinate of the tile's source rectangle within the texture.
	 * @param srcY The Y-coordinate of the tile's source rectangle within the texture.
	 * @param xpos The X-coordinate of the tile's destination rectangle on the screen.
	 * @param ypos The Y-coordinate of the tile's destination rectangle on the screen.
	 * @param tsize The size of the tile (both width and height).
	 * @param tscale The scaling factor for the tile.
	 * @param id The identifier of the texture to use for the tile.
	 */
	TileComponent(int srcX, int srcY, int xpos, int ypos, int tsize, int tscale, std::string id) {

		texture = Game::assets->GetTexture(id);

		srcRect.x = srcX;
		srcRect.y = srcY;
		srcRect.w = srcRect.h = tsize;

		destRect.x = xpos;
		destRect.y = ypos;
		destRect.w = destRect.h = tsize * tscale;

		initRect.x = xpos;
		initRect.y = ypos;
		initRect.w = initRect.h = tsize * tscale;
	}

	/**
	 * @brief Draws the tile on the screen using the specified SDL_Texture and rectangles.
	 */
	void draw() override {
		TextureManager::Draw(texture, srcRect, destRect, SDL_FLIP_NONE);
	}
};

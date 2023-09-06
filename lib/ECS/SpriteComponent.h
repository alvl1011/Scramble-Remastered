#pragma once

#include "Components.h"
#include "SDL.h"
#include "TextureManager.h"
#include "Animation.h"
#include <map>
#include "AssetManager.h"
#include "Timer.h"

/**
 * @class SpriteComponent
 * @brief Represents a component responsible for rendering sprites and animations.
 *
 * The `SpriteComponent` class allows entities to display images, handle animations, and manage visibility.
 */
class SpriteComponent : public Component {
protected:
	bool animated = false;
	bool visible = true;

	int frames = 0;
	int speed = 100;

	SDL_Rect srcRect, destRect;
	TransformComponent* transform;

private:
	
	SDL_Texture* texture;
	
public:

	int animIndex = 0;

	std::map<const char*, Animation> animations;

	SDL_RendererFlip spriteFlip = SDL_FLIP_NONE;

	/**
	* @brief Default constructor for SpriteComponent.
	*/
	SpriteComponent() = default;

	/**
	 * @brief Constructor for SpriteComponent with a texture identifier.
	 * @param id The identifier of the texture to use for rendering.
	 */
	SpriteComponent(std::string id) {
		setTexture(id);
	}

	/**
	 * @brief Constructor for SpriteComponent with a path to a texture file.
	 * @param path The path to the texture file to load.
	 */
	SpriteComponent(const char* path) {
		texture = TextureManager::LoadTexture(path);
	}

	~SpriteComponent() {}

	/**
	* @brief Sets the texture for the sprite using a texture identifier.
	* @param id The identifier of the texture to use.
	*/
	void setTexture(std::string id) {

		texture = Game::assets->GetTexture(id);
	}

	/**
	 * @brief Initializes the sprite component, setting up the source and destination rectangles.
	 */
	void init() override {

		transform = &entity->getComponent<TransformComponent>();

		srcRect.x = srcRect.y = 0;
		srcRect.w = transform->width;
		srcRect.h = transform->height;

	}

	/**
	 * @brief Updates the sprite's animation and rendering parameters.
	 */
	void update() override {

		if (animated) {
			srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks() / speed) % frames);
		}

		srcRect.y = animIndex * transform->height;

		destRect.x = static_cast<int>(transform->position.x);
		destRect.y = static_cast<int>(transform->position.y);
		destRect.w = transform->width * transform->scale;
		destRect.h = transform->height * transform->scale;
	}

	/**
	* @brief Renders the sprite on the screen if it is visible.
	*/
	void draw() override {
		if(visible) 
			TextureManager::Draw(texture, srcRect, destRect, spriteFlip);
	}

	/**
	 * @brief Plays the specified animation.
	 * @param animName The name of the animation to play.
	 */
	void Play(const char* animName) {
		frames = animations[animName].frames;
		animIndex = animations[animName].index;
		speed = animations[animName].speed;
	}

	/**
	* @brief Gets a pointer to the destination rectangle of the sprite.
	* @return A pointer to the destination rectangle.
	*/
	SDL_Rect* getDestRect() {
		return &destRect;
	}

	/**
	* @brief Checks if the sprite is currently visible.
	* @return True if the sprite is visible; otherwise, false.
	*/
	bool getVisible() {
		return visible;
	}

	/**
	 * @brief Sets the visibility of the sprite.
	 * @param value True to make the sprite visible, false to hide it.
	 */
	void setVisible(bool value) {
		visible = value;
	}

};
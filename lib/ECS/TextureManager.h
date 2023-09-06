#pragma once

#include "Game.h"

/**
 * @class TextureManager
 * @brief Provides utility functions for managing textures and rendering in SDL.
 *
 * The `TextureManager` class offers static functions to load textures, draw textures on the screen,
 * and draw lines using the SDL library.
 */
class TextureManager {

public:
	/**
	 * @brief Loads a texture from a file.
	 * @param file_name The path to the image file.
	 * @return A pointer to the loaded SDL_Texture.
	 */
	static SDL_Texture* LoadTexture(const char* file_name);

	/**
	 * @brief Draws an SDL_Texture on the screen.
	 * @param tex The SDL_Texture to be drawn.
	 * @param src The source rectangle within the texture.
	 * @param dest The destination rectangle on the screen.
	 * @param flip The flip state for the texture (e.g., SDL_FLIP_NONE).
	 */
	static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest, SDL_RendererFlip flip);

	/**
	 * @brief Draws a line on the screen.
	 * @param startX The X-coordinate of the line's starting point.
	 * @param startY The Y-coordinate of the line's starting point.
	 * @param endX The X-coordinate of the line's ending point.
	 * @param endY The Y-coordinate of the line's ending point.
	 */
	static void DrawLine(float startX, float startY, float endX, float endY);
};
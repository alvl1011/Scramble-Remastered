#pragma once

#include <map>
#include <string>
#include "TextureManager.h"
#include "Vector2D.h"
#include "ECS.h"
#include "SDL_ttf.h"

/**
 * @class AssetManager
 * @brief Manages game assets such as textures and fonts.
 *
 * The `AssetManager` class is responsible for loading, storing, and managing game assets,
 * including SDL textures and TTF fonts. It provides functions to add and retrieve assets.
 */
class AssetManager {

public:

	/**
	 * @brief Construct an AssetManager.
	 *
	 * Initializes an AssetManager instance, associated with a game manager.
	 *
	 * @param manager A pointer to the game manager that will use this asset manager.
	 */
	AssetManager(Manager* manager);

	/**
	 * @brief Destroy the AssetManager.
	 *
	 * Cleans up resources associated with the AssetManager.
	 */
	~AssetManager();

	/**
	 * @brief Add a texture to the asset manager.
	 *
	 * This function loads an SDL texture from a file and adds it to the asset manager.
	 *
	 * @param id The unique identifier for the texture.
	 * @param path The path to the image file containing the texture.
	 */
	void AddTexture(std::string id, const char* path);

	/**
	 * @brief Get a texture from the asset manager.
	 *
	 * Retrieves an SDL texture from the asset manager using its unique identifier.
	 *
	 * @param id The unique identifier of the texture.
	 * @return A pointer to the SDL_Texture if found, or nullptr if not found.
	 */
	SDL_Texture* GetTexture(std::string id);

	/**
	 * @brief Add a font to the asset manager.
	 *
	 * This function loads a TTF font from a file and adds it to the asset manager.
	 *
	 * @param id The unique identifier for the font.
	 * @param path The path to the TTF font file.
	 * @param font_size The size of the font.
	 */
	void AddFont(std::string id, std::string path, int font_size);

	/**
	 * @brief Get a font from the asset manager.
	 *
	 * Retrieves a TTF font from the asset manager using its unique identifier.
	 *
	 * @param id The unique identifier of the font.
	 * @return A pointer to the TTF_Font if found, or nullptr if not found.
	 */
	TTF_Font* GetFont(std::string id);

private:

	Manager* manager;
	std::map<std::string, SDL_Texture*> textures;
	std::map<std::string, TTF_Font*> fonts;

};
#pragma once

#include <string>

/**
 * @class Map
 * @brief Represents the game map and handles map-related functionality.
 *
 * The `Map` class is responsible for managing the game map, including loading and rendering tiles.
 */
class Map {

public:

    /**
     * @brief Construct a Map object.
     *
     * Initializes a Map instance with the specified texture ID, map scale, and tile size.
     *
     * @param texID The ID of the texture to be used for tiles.
     * @param map_scale The scale factor for the map.
     * @param tile_size The size of individual tiles in pixels.
     */
	Map(std::string texID, int map_scale, int tile_size);

    /**
     * @brief Destructor for Map object.
     *
     * Cleans up resources associated with the Map instance.
     */
	~Map();

    /**
     * @brief Add a tile to the map.
     *
     * Adds a tile to the map at the specified position.
     *
     * @param srcX The x-coordinate of the source tile.
     * @param srcY The y-coordinate of the source tile.
     * @param xpos The x-coordinate of the position to add the tile.
     * @param ypos The y-coordinate of the position to add the tile.
     */
	void AddTile(int srcX, int srcY, int xpos, int ypos);

    /**
     * @brief Load a map from a file.
     *
     * Loads a map from a file, specifying the map's dimensions.
     *
     * @param path The path to the map file.
     * @param sizeX The width of the map in tiles.
     * @param sizeY The height of the map in tiles.
     */
	void LoadMap(std::string path, int sizeX, int sizeY);

private:
	std::string texID;
	int mapScale, tileSize, scaledSize;
};
#include "Map.h"
#include "Components.h"
#include "Game.h"
#include <fstream>

extern Manager manager;

Map::Map(std::string texID, int map_scale, int tile_size): 
	texID(texID), mapScale(map_scale), tileSize(tile_size) {
	scaledSize = map_scale * tile_size;
}

Map::~Map() {
}

void Map::LoadMap(std::string path, int sizeX, int sizeY) {

	char c;
	std::fstream mapFile;
	mapFile.open(path);

	int srcX, srcY;

	for (int y = 0; y < sizeY; y++) {
		for (int x = 0; x < sizeX; x++) {
			mapFile.get(c);
			srcY = atoi(&c) * tileSize;
			mapFile.get(c);
			srcX = atoi(&c) * tileSize;
			AddTile(srcX, srcY, x * scaledSize, y * scaledSize);
			mapFile.ignore();
		}
	}

	mapFile.ignore();

	for (int y = 0; y < sizeY; y++) {
		for (int x = 0; x < sizeX; x++) {
			mapFile.get(c);
			if (c == '1') {
				auto& tcol(manager.addEntity());
				tcol.addComponent<ColliderComponent>("terrain", x * scaledSize, y * scaledSize, scaledSize);
				tcol.addGroup(Game::groupColliders);
			}
			mapFile.ignore();
		}
	}

	mapFile.ignore();

	for (int y = 0; y < sizeY; y++) {
		for (int x = 0; x < sizeX; x++) {
			mapFile.get(c);
			if (c == '1') {
				Game::enemyCoordinates.emplace_back(Vector2D(x * scaledSize, y * scaledSize));
			}
			else if (c == '2') {
				Game::buildingCoordinates.emplace_back(Vector2D(x * scaledSize, y * scaledSize));
			}
			else if (c == '3') {
				Game::baseCoordinate = Vector2D(x * scaledSize, y * scaledSize);
			}
			mapFile.ignore();
		}
	}

	mapFile.close();
}

void Map::AddTile(int srcX, int srcY, int xpos, int ypos) {

	auto& tile(manager.addEntity());
	tile.addComponent<TileComponent>(srcX, srcY, xpos, ypos, tileSize, mapScale, texID);
	tile.addGroup(Game::groupMap);
}
#include "AssetManager.h"

AssetManager::AssetManager(Manager* manager) : manager(manager) {}

AssetManager::~AssetManager() {}

void AssetManager::AddTexture(std::string id, const char* path) {

	textures.emplace(id, TextureManager::LoadTexture(path));
}

SDL_Texture* AssetManager::GetTexture(std::string id) {

	return textures[id];
}

void AssetManager::AddFont(std::string id, std::string path, int font_size) {

	fonts.emplace(id, TTF_OpenFont(path.c_str(), font_size));
}


TTF_Font* AssetManager::GetFont(std::string id) {
	
	return fonts[id];
}
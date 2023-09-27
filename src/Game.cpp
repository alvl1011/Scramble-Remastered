#include "Game.h"
#include "TextureManager.h"
#include "Map.h"
#include "Components.h"
#include "Vector2D.h"
#include "Collision.h"
#include "MVC/Player.h"
#include "MVC/PlayerController.h"
#include "MVC/Enemy/Enemy.h"
#include "MVC/Enemy/RocketEnemyController.h"
#include "MVC/BuildingController.h"
#include "Screens/StartScreen.h"
#include <time.h>

StartScreen* startScreen;

Map* map;
Manager manager;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;
bool Game::gameOver;
bool Game::gameStarted;
bool Game::victory;
int Game::track = 0;

std::vector<Vector2D> Game::enemyCoordinates;
std::vector<Vector2D> Game::buildingCoordinates;
Vector2D Game::baseCoordinate;

AssetManager* Game::assets = new AssetManager(&manager);

AudioManager* Game::audioManager;

PlayerController* playerController;

RocketEnemyController* enemyController;
Enemy* enemy;

BuildingController* buildingController;

auto& label(manager.addEntity());
auto& gameOverLabel(manager.addEntity());
auto& pressRLabel(manager.addEntity());
auto& victoryLabel(manager.addEntity());

Game::Game() {

	srand((unsigned int) time(0));

	timer = Timer::Instance();
	startScreen = StartScreen::Instance();
	audioManager = AudioManager::Instance();
}

Game::~Game() {
	timer->Release();
	timer = NULL;

	startScreen->Release();
	startScreen = NULL;

	audioManager->Release();
	audioManager = NULL;
}

void Game::init(const char* title, int x, int y, int width, int height, bool full_screen) {

	int flags = 0;
	
	gameStarted = false;

	if (full_screen)
		flags = SDL_WINDOW_FULLSCREEN;

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsystems Initialized..." << std::endl;

		window = SDL_CreateWindow(title, x, y, width, height, flags);
		if (window)
			std::cout << "Window created." << std::endl;

		Game::renderer = SDL_CreateRenderer(window, -1, 0);
		if (Game::renderer) {

			SDL_SetRenderDrawColor(Game::renderer, 19, 24, 98, 255);
			std::cout << "Renderer created." << std::endl;
		}


		isRunning = true;
		gameOver = false;
	}

	if (TTF_Init() == -1) {
		std::cout << "FAILED to initialize: sdl_ttf" << std::endl;
	}

	assets->AddTexture("terrain", "assets/terrain_ss.png");
	assets->AddTexture("player", "assets/ship-animations.png");
	assets->AddTexture("black", "assets/black.png");
	assets->AddTexture("rocket", "assets/rocket-animation.png");
	assets->AddTexture("rocket-bullet", "assets/rock-bullet-anim.png");
	assets->AddTexture("building", "assets/house-anim.png");
	assets->AddTexture("fuel", "assets/fuel.png");
	assets->AddTexture("base-building", "assets/base-anim.png");
	assets->AddFont("arcade", "assets/arcade.ttf", 16);

	map = new Map("terrain", 2, 32);

	map->LoadMap("assets/main-map.map", 150, 12);

	std::cout << enemyCoordinates[0] << std::endl;

	playerController = new PlayerController("player 1");

	enemyController = new RocketEnemyController();
	enemyController->init();

	buildingController = new BuildingController();
	buildingController->init();

	SDL_Color white = {255, 255, 255, 255};
	SDL_Color yellow = { 255, 255, 0, 255 };
	label.addComponent<UILabel>(10, 10, "Hello, world!", "arcade", white);
	gameOverLabel.addComponent<UILabel>(330, 250, "Game over!", "arcade", white);
	victoryLabel.addComponent<UILabel>(300, 250, "Congratulations!", "arcade", white);
	pressRLabel.addComponent<UILabel>(280, 290, "Press R to restart", "arcade", white);

	startScreen->Init();
	audioManager->PlayMusic("start.wav", 0);
}


auto& tiles(manager.getGroup(Game::groupMap));
auto& colliders(manager.getGroup(Game::groupColliders));
auto& enemies(manager.getGroup(Game::groupEnemies));
auto& labels(manager.getGroup(Game::groupLabels));
auto& stars(manager.getGroup(Game::groupStars));

void Game::update() {

	startScreen->Update();

	for (auto& s : stars) {
		s->update();
	}

	if (gameStarted) {
		
		manager.refresh();
		manager.update();

		playerController->update();
		playerController->getPlayer()->getPlayer()->getComponent<AnimatedView>().Update();

		enemyController->update();
		buildingController->update();

		if (!gameOver && !victory) {

			Game::track += 1;
			
			for (auto t : tiles) {
				t->getComponent<TileComponent>().destRect.x += -(2);
			}
		}
	}
}

void Game::render() {
	SDL_RenderClear(Game::renderer);

	startScreen->RenderStars();

	if (gameStarted) {

		for (auto& t : tiles) {
			t->draw();
		}

		playerController->render();
		enemyController->render();
		buildingController->render();

		for (auto& c : colliders) {
			if (c->getComponent<ColliderComponent>().tag != "enemy") {
				c->draw();
			}
		}

		for (auto& l : labels) {
			l->draw();
		}
	}


	if (gameOver) {
		if (getPlayerLives() <= 0) {
			gameOverLabel.draw();
		}
		
		pressRLabel.draw();
	}

	if (victory) {
		victoryLabel.draw();
		pressRLabel.draw();
	}
	
	startScreen->Render();

	SDL_RenderPresent(Game::renderer);
}

int Game::getPlayerScore() {
	return playerController->getPlayer()->getCurrentScore();
}

void Game::setPlayerScore(int score) {
	Player* player = playerController->getPlayer();
	player->setCurrentScore(player->getCurrentScore() + score);
}

void Game::setPlayerFuel(float fuel) {
	return playerController->getPlayer()->increaseFuel(fuel);
}

float Game::getPlayerFuel() {
	return playerController->getPlayer()->getFuel();
}

int Game::getPlayerHighScore() {
	return playerController->getPlayer()->getHighScore();
}

int Game::getPlayerLives() {
	return playerController->getPlayer()->lives;
}

void Game::restart() {

	if (gameOver || victory) {

		if (playerController->getPlayer()->lives <= 0 || victory) {
			playerController->getPlayer()->setCurrentScore(0);
			gameStarted = false;
			victory = false;
			audioManager->PlayMusic("start.wav", 0);
		}

		Game::track = 0;

		playerController->respawn();

		enemyController->respawn();
		buildingController->respawn();

		for (auto t : tiles) {
			t->getComponent<TileComponent>().destRect.x = t->getComponent<TileComponent>().initRect.x;
		}

		for (auto c : colliders) {
			ColliderComponent* col = &c->getComponent<ColliderComponent>();
			col->destR.x = col->initR.x;
			col->collider.x = col->initCollider.x;
		}

		gameOver = false;
	}
	
}

void Game::handleEvents() {

	SDL_PollEvent(&event);

	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	case SDL_KEYDOWN:

		switch (event.key.keysym.sym) {
		case SDLK_RSHIFT:
		case SDLK_LSHIFT:
			if (!gameStarted) {
				gameStarted = true;
			}
			break;
		case SDLK_r:
			restart();
			break;
		case SDLK_q:
			if (!gameStarted) {
				isRunning = false;
			}
			break;
		default:
			break;
		}

		break;
	default:
		break;
	}

}

void Game::clean() {

	enemyCoordinates.clear();
	buildingCoordinates.clear();
	delete assets;

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(Game::renderer);
	SDL_Quit();
	std::cout << "Game cleaned." << std::endl;
}

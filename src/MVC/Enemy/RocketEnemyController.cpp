#include "MVC/Enemy/RocketEnemyController.h"
#include <Windows.h>

extern Manager manager;

void RocketEnemyController::initEnemies() {

	for (Vector2D v : Game::enemyCoordinates) {
		RocketEnemy* enemy = new RocketEnemy();
		enemy->initEnemy(v.x, v.y);
		enemies.emplace_back(enemy);
	}
}

void RocketEnemyController::init() {
	initEnemies();
}

void RocketEnemyController::update() {
	for (auto& e : enemies) {
		e->update();
	}
}

void RocketEnemyController::render() {
	for (auto& e : enemies) {
		e->draw();
	}
}
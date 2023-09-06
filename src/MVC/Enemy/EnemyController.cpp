#include "MVC/Enemy/EnemyController.h"

Enemy* EnemyController::initEnemy(Enemy::Types type) {
	
	switch (type) {
	case Enemy::Types::rocket:
		enemy = new RocketEnemy();
		break;
	default:
		enemy = new RocketEnemy();
	}

	enemy->init();
	std::cout << "Enemy initialized" << std::endl;
	return enemy;
}

void EnemyController::drawEnemy() {
	enemy->getEnemy()->draw();
}
#include "RocketBullet.h"

extern Manager manager;

RocketBullet::RocketBullet() {

	mTimer = Timer::Instance();

	mSpeed = 100.0f;

	auto& rocketEntity(manager.addEntity());
	rocketEntity.addComponent<TransformComponent>(0.0f, 0.0f, 16, 16, 2, 2);
	rocketEntity.addComponent<ColliderComponent>("rock-bullet");
	rocketEntity.addComponent<AnimatedView>("rocket-bullet", 0, 4, 1.0f);

	rocketEntity.addGroup(Game::groupColliders);
	rocket = &rocketEntity;

	Reload();
}

RocketBullet::~RocketBullet() {

	mTimer = NULL;
	delete rocket;
	rocket = NULL;
}

void RocketBullet::Fire(Vector2D position) {

	rocket->getComponent<TransformComponent>().position.x = position.x + 50;
	rocket->getComponent<TransformComponent>().position.y = position.y + 30;
	setIsActive(true);
}

void RocketBullet::Reload() {
	setIsActive(false);
}

void RocketBullet::update() {
	if (isActive) {

		Vector2D currentPosition = rocket->getComponent<TransformComponent>().position;

		Vector2D playerPosition = manager.getGroup(Game::groupPlayers)[0]->getComponent<TransformComponent>().position;

		float angle = atan2(640.0f - currentPosition.y, (playerPosition.x + 300.0f) - currentPosition.x);
		
		rocket->getComponent<TransformComponent>().velocity.x = (rocket->getComponent<TransformComponent>().speed * 0.5f * cos(angle));
		rocket->getComponent<TransformComponent>().velocity.y = rocket->getComponent<TransformComponent>().speed * 0.2f * sin(angle);

		if (currentPosition.y < -OFFSCREEN_BUFFER || currentPosition.y > 600 + OFFSCREEN_BUFFER) {
			Reload();
		}

		

		rocket->getComponent<AnimatedView>().Update();
	}
}

void RocketBullet::render() {
	if (isActive) {

		rocket->draw();
	}
}
#include "Bullet.h"

extern Manager manager;

Bullet::Bullet() {
	mTimer = Timer::Instance();

	mSpeed = 500.0f;

	auto& bulEntity(manager.addEntity());
	bulEntity.addComponent<TransformComponent>(0.0f, 0.0f, 4, 4, 1);
	bulEntity.addComponent<SpriteComponent>("assets/bullet.png");
	bulEntity.addComponent<ColliderComponent>("bullet");

	bulEntity.addGroup(Game::groupColliders);
	bullet = &bulEntity;

	Reload();
}

Bullet::~Bullet() {
	mTimer = NULL;
	delete bullet;
	bullet = NULL;
}

void Bullet::Fire(Vector2D position) {

	bullet->getComponent<TransformComponent>().position.x = position.x + 50;
	bullet->getComponent<TransformComponent>().position.y = position.y + 30;
	setIsActive(true);
}

void Bullet::Reload() {
	setIsActive(false);
}

void Bullet::Update() {
	if (isActive) {
		bullet->getComponent<TransformComponent>().velocity.x = 3;

		Vector2D currentPosition = bullet->getComponent<TransformComponent>().position;

		if (currentPosition.x < -OFFSCREEN_BUFFER || currentPosition.x > 800 + OFFSCREEN_BUFFER) {
			Reload();
		}

		UpdateCollission();
	}
}

void Bullet::UpdateCollission() {
	ColliderComponent* bulletCol = &bullet->getComponent<ColliderComponent>();

	for (auto& c : manager.getGroup(Game::groupColliders)) {

		ColliderComponent* cCol = &c->getComponent<ColliderComponent>();

		if (Collision::AABB(bulletCol->collider, cCol->collider) && cCol->tag != "bullet") {
			setIsActive(false);
			break;
		}

	}
}

void Bullet::Render() {
	if (isActive) {
		bullet->draw();
	}
}
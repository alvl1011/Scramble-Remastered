#include "MVC/Enemy/RocketEnemy.h"

extern Manager manager;

void RocketEnemy::initEnemy(float x, float y) {
	auto& enemy(manager.addEntity());

	enemy.addComponent<TransformComponent>(x, y, 16, 16, 3);
	enemy.addComponent<AnimatedView>("rocket", 0, 4, 1);

	enemy.addComponent<ColliderComponent>("enemy");
	enemy.addComponent<TriggerComponent>(x - 100, 100, 400, 500);
	setEnemy(&enemy);
	enemy.addGroup(Game::groupColliders);
	isDead = false;
}

void RocketEnemy::update() {
	if (enemy != NULL && !getIsDead()) {
		TransformComponent* current = &enemy->getComponent<TransformComponent>();
		current->speed = 1;

		if (Game::gameOver || Game::victory) {
			current->velocity.x = 0;
		}
		else {
			current->velocity.x = -(2);
		}

		updateCollider();
		updateTrigger();
	}
	updateAnimations();
}

void RocketEnemy::draw() {
	if (enemy != NULL && getIsDead()) {
		AnimatedView* view = &enemy->getComponent<AnimatedView>();
		view->setAnimation(2, 2.0f, AnimatedView::ONCE);
		enemy->deleteGroup(Game::groupColliders);
	}
	enemy->draw();
}

void RocketEnemy::updateCollider() {
	ColliderComponent* collider = &enemy->getComponent<ColliderComponent>();
	AnimatedView* view = &enemy->getComponent<AnimatedView>();

	ColliderComponent* cCol = &manager.getGroup(Game::groupPlayers)[0]->getComponent<ColliderComponent>();

	for (auto& c : manager.getGroup(Game::groupColliders)) {
		ColliderComponent* col = &c->getComponent<ColliderComponent>();
		if (Collision::AABB(col->collider, collider->collider) && (col->tag == "bullet" || col->tag == "rock-bullet") || Collision::AABB(cCol->collider, collider->collider)) {
			if (col->tag == "bullet") {
				col->entity->deleteGroup(Game::groupColliders);
			}

			Game::setPlayerScore(50);
			enemy->getComponent<TransformComponent>().velocity.y = 0;
			Game::audioManager->PlaySFX("explose.wav");
			setIsDead(true);
			break;
		}
	}
}

void RocketEnemy::updateTrigger() {
	ColliderComponent* collider = &enemy->getComponent<ColliderComponent>();
	TriggerComponent* trigger = &enemy->getComponent<TriggerComponent>();

	ColliderComponent* cCol = &manager.getGroup(Game::groupPlayers)[0]->getComponent<ColliderComponent>();

	if (Collision::AABB(cCol->collider, trigger->trigger) && !Collision::AABB(cCol->collider, collider->collider)) {
		AnimatedView* view = &enemy->getComponent<AnimatedView>();
		enemy->getComponent<TransformComponent>().velocity.y = -3;
		view->setAnimation(1, 1.0f, AnimatedView::LOOP);
	}
}

void RocketEnemy::updateAnimations() {
	enemy->getComponent<AnimatedView>().Update();
}
#include "MVC/Building.h"

extern Manager manager;

Building::Building(float x, float y, int scores, bool is_base, bool is_fuel) : scores(scores), is_base(is_base), is_fuel(is_fuel) {

	auto& building(manager.addEntity());
	if (is_base) {
		building.addComponent<TransformComponent>((float) x, (float) y, 16, 16, 4);
	}
	else {
		building.addComponent<TransformComponent>((float) x, (float) y, 16, 16, 3);
	}
	
	std::string asset = is_base ? "base-building" : (is_fuel ? "fuel" : "building");
	building.addComponent<AnimatedView>(asset, 0, 4, 1.0f);
	building.addComponent<ColliderComponent>(asset);

	entity = &building;

	building.addGroup(Game::groupColliders);
	destroyed = false;
}

Building::~Building() {
	entity->destroy();
}

void Building::update() {
	if (entity != NULL && !destroyed) {

		TransformComponent* current = &entity->getComponent<TransformComponent>();
		current->speed = 1;

		if (Game::gameOver || Game::victory) {
			current->velocity.x = 0;
		}
		else {
			current->velocity.x = -(2);
		}

		updateCollider();
	}

	updateAnimations();
}

void Building::draw() {
	if (entity != NULL && destroyed) {
		AnimatedView* view = &entity->getComponent<AnimatedView>();
		view->setAnimation(1, 2.0f, AnimatedView::ONCE);
		entity->deleteGroup(Game::groupColliders);
	}
	entity->draw();
}

void Building::updateCollider() {
	ColliderComponent* collider = &entity->getComponent<ColliderComponent>();

	ColliderComponent* cCol = &manager.getGroup(Game::groupPlayers)[0]->getComponent<ColliderComponent>();

	for (auto& c : manager.getGroup(Game::groupColliders)) {
		ColliderComponent* col = &c->getComponent<ColliderComponent>();
		if (Collision::AABB(col->collider, collider->collider) && (col->tag == "bullet" || col->tag == "rock-bullet") || Collision::AABB(cCol->collider, collider->collider)) {
			if (col->tag == "bullet" || col->tag == "rock-bullet")
				Game::setPlayerScore(scores);
			Game::audioManager->PlaySFX("explose.wav");
			entity->getComponent<TransformComponent>().velocity.y = 0;
			destroyed = true;

			if (collider->tag == "base-building") {
				Game::audioManager->PlayMusic("win.wav", 0);
				Game::victory = true;
			}

			if (collider->tag == "fuel") {
				Game::setPlayerFuel(10.0f);
				Game::audioManager->PlaySFX("fuel.wav");
			}
				
			break;
		}
	}
}

void Building::updateAnimations() {
	entity->getComponent<AnimatedView>().Update();
}
#include "MVC/Player.h"

extern Manager manager;

Player::Player(std::string name, int lives = 3, int highScore = 0) : name(name), lives(lives), highScore(highScore) { }

void Player::init() {

	wasHit = false;

	auto& player(manager.addEntity());

	player.addComponent<TransformComponent>(400.0f, 320.0f, 32, 32, 2);
	player.addComponent<KeyboardController>();
	
	view = new PlayerView(&player.addComponent<AnimatedView>("player", 0, 4, 1.0f));
	player.addComponent<ColliderComponent>("player");
	player.addGroup(Game::groupPlayers);

	entity = &player;
}

void Player::update() {
	TransformComponent* transform = &entity->getComponent<TransformComponent>();

	if (transform->position.x <= 0.0f) {
		transform->position.x = 0.0f;
	}
	else if (transform->position.x >= 450.0f) {
		transform->position.x = 450.0f;
	}

	if (transform->position.y <= 120.0f) {
		transform->position.y = 120.0f;
	}
	else if (transform->position.y >= 550.0f) {
		transform->position.y = 550.0f;
	}

	updateCollision();
	updateCurrentScore();
	updateFuel();
}

void Player::updateCurrentScore() {

	if (currentScore > highScore) {
		setHighScore(currentScore);
	}

	if (Game::track % 128 == 0 && Game::track != 0) {
		setCurrentScore(currentScore + 10);
	}
}

void Player::updateFuel() {

	if (Game::track % 128 == 0 && Game::track != 0) {
		decreaseFuel(0.005f * MAX_FUEL);
	}
}

void Player::updateCollision() {
	ColliderComponent playerCollider = entity->getComponent<ColliderComponent>();

	for (auto& c : manager.getGroup(Game::groupColliders)) {

		ColliderComponent cCol = c->getComponent<ColliderComponent>();

		if (Collision::AABB(playerCollider, cCol) && cCol.tag != "bullet") {

			if (!wasHit) {
				entity->getComponent<AnimatedView>().ResetAnimation();

				if (lives != 0) {
					lives--;
				}

				Game::audioManager->PlaySFX("gameover.wav");

				std::cout << lives << std::endl;
			}

			wasHit = true;

			entity->getComponent<AnimatedView>().setAnimation(1, 2.0f, AnimatedView::ONCE);

			Game::gameOver = true;
			setIsDead(true);
			break;
		}

	}
}

Entity* Player::getPlayer() {
	return manager.getGroup(Game::groupPlayers)[0];
}

Player::~Player() {
	manager.getGroup(Game::groupPlayers)[0]->destroy();
}

PlayerView* Player::getView() {
	return view;
}
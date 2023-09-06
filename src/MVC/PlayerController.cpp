#include "MVC/PlayerController.h"

Player* PlayerController::initPlayer(std::string name, int lives, int highScore) {
	player = new Player(name, lives, highScore);
	player->init();
	std::cout << "Player initialized: " << player->getName() << std::endl;
	std::cout << "Player highscore param: " << highScore << std::endl;
	std::cout << "Player highscore: " << player->getHighScore() << std::endl;

	for (int i = 0; i < MAX_BULLETS; i++) {
		mBullets[i] = new Bullet();
	}

	for (int i = 0; i < MAX_ROCKET_BULLETS; i++) {
		mRocketBullets[i] = new RocketBullet();
	}

	return player;
}

void PlayerController::drawPlayer() {
	player->getPlayer()->draw();
}

void PlayerController::HandleFiring() {
	if (!player->getIsDead() && !Game::victory) {
		switch (Game::event.type) {
		case SDL_KEYDOWN:
			if (Game::event.key.keysym.sym == SDLK_SPACE) {

				for (int i = 0; i < MAX_BULLETS; i++) {
					if (!mBullets[i]->getIsActive()) {

						mBullets[i]->Fire(player->getPlayer()->getComponent<TransformComponent>().position);
						Game::audioManager->PlaySFX("fire.wav");
						break;
					}
				}
			}
			else if (Game::event.key.keysym.sym == SDLK_LALT) {
				for (int i = 0; i < MAX_ROCKET_BULLETS; i++) {
					if (!mRocketBullets[i]->getIsActive()) {
						mRocketBullets[i]->getRocket()->getComponent<AnimatedView>().setVisible(true);
						mRocketBullets[i]->Fire(player->getPlayer()->getComponent<TransformComponent>().position);
						Game::audioManager->PlaySFX("fire.wav");
						break;
					}
				}
			}
			break;
		}
	}
}
#include "Screens/Star.h"

extern Manager manager;

bool Star::sScroll = false;

Star::Star(int scale) {

	auto& starPtr(manager.addEntity());
	starPtr.addComponent<TransformComponent>(rand() % 800, rand() % 670, 2, 2, scale);
	starPtr.addComponent<SpriteComponent>("assets/stars.png");
	starPtr.addGroup(Game::groupStars);

	star = &starPtr;
	
	mTimer = Timer::Instance();

	int starColor = rand() % 4;

	star->getComponent<SpriteComponent>().getDestRect()->x = starColor * 4;

	mFlickerTimer = 0.0f;
	mFlickerSpeed = 0.40f + ((float) rand() / RAND_MAX) * 0.90f;

	mScrollSpeed = 1.0f / scale;
}

Star::~Star() {
	mTimer = NULL;
}


void Star::update() {
	mFlickerTimer += mTimer->DeltaTime();
	if (mFlickerTimer >= mFlickerSpeed) {
		mVisible = !mVisible;
		mFlickerTimer = 0.0f;
	}

	if (sScroll)
		ScrollStar();
}

void Star::draw() {
	if (mVisible) {
		star->draw();
	}
}

void Star::Scroll(bool b) {
	sScroll = b;
}

void Star::ScrollStar() {

	TransformComponent* transform = &star->getComponent<TransformComponent>();
	transform->speed = mScrollSpeed;
	transform->velocity.x = 2;

	if (transform->position.x > 800) {
		transform->position.x = 0.0f;
		transform->position.y = rand() % 670;
	}
}
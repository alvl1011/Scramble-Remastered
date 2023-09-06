#include "AnimatedView.h"

AnimatedView::AnimatedView(std::string asset, int startX, int frameCount, float animSpeed)
	: SpriteComponent(asset) {

	mTimer = Timer::Instance();

	mStartX = startX;
	mStartY = 0;

	mFrameCount = frameCount;
	mAnimSpeed = animSpeed;
	mTimePerFrame = mAnimSpeed / mFrameCount;
	mAnimTimer = 0.0f;

	mAnimDone = false;

	wrapMode = LOOP;
	setTexture(asset);
}

AnimatedView::~AnimatedView() { }

void AnimatedView::WrapMode(WRAP_MODE mode) {
	wrapMode = mode;
}

void AnimatedView::ResetAnimation() {
	mAnimTimer = 0.0f;
	mAnimDone = false;
}

bool AnimatedView::IsAnimating() {
	return !mAnimDone;
}

void AnimatedView::Update() {
	if (!mAnimDone) {

		mAnimTimer += mTimer->DeltaTime();

		if (mAnimTimer >= mAnimSpeed) {

			if (wrapMode == LOOP) {
				mAnimTimer -= mAnimSpeed;
			}
			else {
				mAnimDone = true;
				mAnimTimer = mAnimSpeed - mTimePerFrame;
			}
		}

		srcRect.x = mStartX + (int)(mAnimTimer / mTimePerFrame) * srcRect.w;
		srcRect.y = mStartY * transform->height;
	}
}
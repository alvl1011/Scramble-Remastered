#include "Screens/BackgroundStars.h"

BackgroundStars* BackgroundStars::bInstance = NULL;

BackgroundStars::BackgroundStars() {

}

BackgroundStars::~BackgroundStars() {
	for (int i = 0; i < LAYER_COUNT; i++) {
		delete mLayers[i];
		mLayers[i] = NULL;
	}
}

BackgroundStars* BackgroundStars::Instance() {

	if (bInstance == NULL)
		bInstance = new BackgroundStars();
	
	return bInstance;
}

void BackgroundStars::Release() {
	delete bInstance;
	bInstance = NULL;
}

void BackgroundStars::Init() {
	for (int i = 0; i < LAYER_COUNT; i++)
		mLayers[i] = new StarLayer(i);
}

void BackgroundStars::Update() {

	for (int i = 0; i < LAYER_COUNT; i++)
		mLayers[i]->Update();
}

void BackgroundStars::Render() {
	for (int i = 0; i < LAYER_COUNT; i++)
		mLayers[i]->Render();
}
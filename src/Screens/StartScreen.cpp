#include "Screens/StartScreen.h"

extern Manager manager;

StartScreen* StartScreen::sInstance = NULL;

StartScreen::StartScreen() {

	stars = BackgroundStars::Instance();
}

StartScreen::~StartScreen() {

	stars->Release();
	stars = NULL;
}

StartScreen* StartScreen::Instance() {

	if (sInstance == NULL) {
		sInstance = new StartScreen();
	}

	return sInstance;
}

void StartScreen::Release() {

	delete sInstance;
	sInstance = NULL;
}

auto& scoreLabel(manager.addEntity());
auto& highScoreValue(manager.addEntity());

auto& live1(manager.addEntity());
auto& live2(manager.addEntity());
auto& live3(manager.addEntity());

void StartScreen::Init() {

	SDL_Color white = { 255, 255, 255, 255 };
	SDL_Color yellow = { 255, 255, 0, 255 };
	SDL_Color blue = { 0, 191, 255, 255 };
	SDL_Color red = { 255, 0, 0, 255 };

	auto& levelLabel(manager.addEntity());
	auto& highScore(manager.addEntity());

	auto & firstLevel(manager.addEntity());
	auto & secondLevel(manager.addEntity());
	auto & baseLevel(manager.addEntity());

	auto& activeLvl1(manager.addEntity());
	auto& activeLvl2(manager.addEntity());
	auto& activeLvl6(manager.addEntity());

	auto& playLabel(manager.addEntity());
	auto& scrambleLabel(manager.addEntity());
	auto& subTitleLabel1(manager.addEntity());
	auto& subTitleLabel2(manager.addEntity());

	auto& fuelLabel(manager.addEntity());

	levelLabel.addComponent<UILabel>(10, 10, "1UP", "arcade", white);
	highScore.addComponent<UILabel>(300, 10, "High score", "arcade", white);
	highScoreValue.addComponent<UILabel>(330, 30, "10000", "arcade", yellow);
	scoreLabel.addComponent<UILabel>(10, 30, "3260", "arcade", yellow);

	firstLevel.addComponent<TransformComponent>(224.0f, 80.0f, 8, 32, 3);
	firstLevel.addComponent<SpriteComponent>("assets/1st.png");

	activeLvl1.addComponent<TransformComponent>(224.0f, 104.0f, 8, 32, 3);
	activeLvl1.addComponent<SpriteComponent>("assets/active-lvl.png");

	secondLevel.addComponent<TransformComponent>(352.0f, 80.0f, 8, 32, 3);
	secondLevel.addComponent<SpriteComponent>("assets/2nd.png");

	activeLvl2.addComponent<TransformComponent>(352.0f, 104.0f, 8, 32, 3);
	activeLvl2.addComponent<SpriteComponent>("assets/not-active-lvl.png");

	baseLevel.addComponent<TransformComponent>(480.0f, 80.0f, 8, 32, 3);
	baseLevel.addComponent<SpriteComponent>("assets/base.png");

	activeLvl6.addComponent<TransformComponent>(480.0f, 104.0f, 8, 32, 3);
	activeLvl6.addComponent<SpriteComponent>("assets/not-active-lvl.png");

	playLabel.addComponent<UILabel>(270, 200, "press shift to play", "arcade", yellow);
	scrambleLabel.addComponent<UILabel>(315, 250, "- Scramble -", "arcade", blue);
	subTitleLabel1.addComponent<UILabel>(250, 350, "How far can you invade", "arcade", red);
	subTitleLabel2.addComponent<UILabel>(265, 400, "our scramble system?", "arcade", red);

	fuelLabel.addComponent<UILabel>(250, 600, "fuel", "arcade", white);

	live1.addComponent<TransformComponent>(0.0f, 610.0f, 32, 32, 2);
	live1.addComponent<SpriteComponent>("assets/ship.png");

	live2.addComponent<TransformComponent>(50.0f, 610.0f, 32, 32, 2);
	live2.addComponent<SpriteComponent>("assets/ship.png");

	live3.addComponent<TransformComponent>(100.0f, 610.0f, 32, 32, 2);
	live3.addComponent<SpriteComponent>("assets/ship.png");


	widgets.emplace_back(&levelLabel);
	widgets.emplace_back(&highScore);
	widgets.emplace_back(&highScoreValue);
	widgets.emplace_back(&scoreLabel);

	gameWidgets.emplace_back(&firstLevel);
	gameWidgets.emplace_back(&activeLvl1);
	gameWidgets.emplace_back(&secondLevel);
	gameWidgets.emplace_back(&activeLvl2);
	gameWidgets.emplace_back(&baseLevel);
	gameWidgets.emplace_back(&activeLvl6);

	gameWidgets.emplace_back(&fuelLabel);


	gameWidgets.emplace_back(&live1);
	gameWidgets.emplace_back(&live2);
	gameWidgets.emplace_back(&live3);

	startScreenWidgets.emplace_back(&playLabel);
	startScreenWidgets.emplace_back(&scrambleLabel);
	startScreenWidgets.emplace_back(&subTitleLabel1);
	startScreenWidgets.emplace_back(&subTitleLabel2);

	stars->Init();
}

void StartScreen::Update() {
	stars->Update();

	std::stringstream ss;
	ss << std::setw(2) << std::setfill('0') << Game::getPlayerScore();
	scoreLabel.getComponent<UILabel>().SetLabelText(ss.str(), "arcade");

	std::stringstream hs;
	hs << std::setw(2) << std::setfill('0') << Game::getPlayerHighScore();
	highScoreValue.getComponent<UILabel>().SetLabelText(hs.str(), "arcade");

	std::stringstream lss;
	lss << Game::getPlayerLives();
	
	if (lss.str() == "2") {
		live3.getComponent<SpriteComponent>().setVisible(false);

		live2.getComponent<SpriteComponent>().setVisible(true);
		live1.getComponent<SpriteComponent>().setVisible(true);
	}
	else if (lss.str() == "1") {
		live3.getComponent<SpriteComponent>().setVisible(false);
		live2.getComponent<SpriteComponent>().setVisible(false);

		live1.getComponent<SpriteComponent>().setVisible(true);
	}
	else if (lss.str() == "0") {
		live3.getComponent<SpriteComponent>().setVisible(false);
		live2.getComponent<SpriteComponent>().setVisible(false);
		live1.getComponent<SpriteComponent>().setVisible(false);
	}
	else {
		live3.getComponent<SpriteComponent>().setVisible(true);
		live2.getComponent<SpriteComponent>().setVisible(true);
		live1.getComponent<SpriteComponent>().setVisible(true);
	}

}

void StartScreen::RenderStars() {
	stars->Render();
}

void StartScreen::Render() {

	SDL_Rect rectTop, rectBottom;
	rectTop.x = 0;
	rectTop.y = 0;
	rectTop.w = 800;
	rectTop.h = 100;

	rectBottom.x = 0;
	rectBottom.y = 590;
	rectBottom.w = 800;
	rectBottom.h = 80;

	SDL_RenderDrawRect(Game::renderer, &rectTop);
	SDL_SetRenderDrawColor(Game::renderer, 0, 0, 0, 255);
	SDL_RenderFillRect(Game::renderer, &rectTop);
	SDL_SetRenderDrawColor(Game::renderer, 0, 0, 0, 255);

	SDL_RenderDrawRect(Game::renderer, &rectBottom);
	SDL_SetRenderDrawColor(Game::renderer, 0, 0, 0, 255);

	SDL_RenderFillRect(Game::renderer, &rectBottom);
	SDL_SetRenderDrawColor(Game::renderer, 0, 0, 0, 255);

	if (!Game::gameStarted) {
		
		for (auto& widget : startScreenWidgets) {
			widget->draw();
		}
	}
	else {
		for (auto& widget : gameWidgets) {
			widget->draw();
		}

		RenderHPBar(550, 620, -300, 20, Game::getPlayerFuel(), { 255, 255,0 }, { 0, 0, 200 });
		SDL_SetRenderDrawColor(Game::renderer, 0, 0, 0, 255);
	}

	for (auto& widget : widgets) {
		widget->draw();
	}
}

void StartScreen::RenderHPBar(int x, int y, int w, int h, float percent, SDL_Color FGColor, SDL_Color BGColor) {
	percent = percent > 1.f ? 1.f : percent < 0.f ? 0.f : percent;
	SDL_Color old;
	SDL_GetRenderDrawColor(Game::renderer, &old.r, &old.g, &old.g, &old.a);
	SDL_Rect bgrect = { x, y, w, h };
	SDL_SetRenderDrawColor(Game::renderer, BGColor.r, BGColor.g, BGColor.b, BGColor.a);
	SDL_RenderFillRect(Game::renderer, &bgrect);
	SDL_SetRenderDrawColor(Game::renderer, FGColor.r, FGColor.g, FGColor.b, FGColor.a);
	int pw = (int)((float)w * percent);
	int px = x + (w - pw);
	SDL_Rect fgrect = { px, y, pw, h };
	SDL_RenderFillRect(Game::renderer, &fgrect);
	SDL_SetRenderDrawColor(Game::renderer, old.r, old.g, old.b, old.a);
}
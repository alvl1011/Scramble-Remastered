#include "MVC/BuildingController.h"

void BuildingController::init() {
	initBuildings();
}

void BuildingController::update() {
	for (auto& e : buildings) {
		e->update();
	}
}

void BuildingController::render() {
	for (auto& e : buildings) {
		e->draw();
	}
}

void BuildingController::initBuildings() {

	for (Vector2D v : Game::buildingCoordinates) {
		Building* building = new Building(v.x, v.y, 100, false);
		buildings.emplace_back(building);
	}


	Building* building = new Building(Game::baseCoordinate.x, Game::baseCoordinate.y, 800, true);
	buildings.emplace_back(building);
}
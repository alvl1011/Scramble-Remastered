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

	int count = 0;

	for (Vector2D v : Game::buildingCoordinates) {

		Building* building;

		if (count % 3 == 0) {
			building = new Building(v.x, v.y, 300, false, true);
		}
		else {
			building = new Building(v.x, v.y, 100, false, false);
		}
		
		buildings.emplace_back(building);
		count++;
	}


	Building* building = new Building(Game::baseCoordinate.x, Game::baseCoordinate.y, 800, true, false);
	buildings.emplace_back(building);
}
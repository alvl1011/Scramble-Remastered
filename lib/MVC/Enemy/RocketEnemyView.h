#pragma once

#include "MVC/Enemy/EnemyView.h"
#include "AnimatedView.h"

/**
 * @class RocketEnemyView
 * @brief Represents the view component for rendering a rocket enemy.
 *
 * The `RocketEnemyView` class is responsible for rendering the visual representation of a rocket enemy.
 */
class RocketEnemyView : public EnemyView {

private:

	AnimatedView* view;

public:

	/**
	 * @brief Default constructor for the RocketEnemyView class.
	 */
	RocketEnemyView() = default;

	/**
	 * @brief Constructor for the RocketEnemyView class with a specified animation ID.
	 * @param id The ID of the animation to use for rendering.
	 */
	RocketEnemyView(std::string id) {
		view = new AnimatedView(id, 0, 4, 100);
		view->init();
	}

	/**
	 * @brief Constructor for the RocketEnemyView class with a pre-initialized AnimatedView.
	 * @param view A pointer to a pre-initialized AnimatedView.
	 */
	RocketEnemyView(AnimatedView* view) {
		this->view = view;
	}

	~RocketEnemyView() { }

	/**
	 * @brief Gets the AnimatedView used for rendering the rocket enemy.
	 * @return A pointer to the AnimatedView.
	 */
	AnimatedView* getView() {
		return view;
	}
};

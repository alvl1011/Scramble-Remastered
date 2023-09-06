#pragma once

#include "MVC/Player.h"
#include "AnimatedView.h"

/**
 * @class PlayerView
 * @brief Represents the view or visual representation of a player entity.
 *
 * The `PlayerView` class manages the visual aspects of a player entity, including animations and rendering.
 */
class PlayerView {

private:

	AnimatedView* view;

public:

	/**
	 * @brief Default constructor for the PlayerView class.
	 */
	PlayerView() = default;

	/**
	 * @brief Constructor for the PlayerView class with a specified animation identifier.
	 * @param id The identifier of the animation to use for the player's view.
	 */
	PlayerView(std::string id) {

		view = new AnimatedView(id, 0, 4, 100);
		view->init();
	}

	/**
	 * @brief Constructor for the PlayerView class with a specified animated view.
	 * @param view A pointer to the animated view to associate with the player.
	 */
	PlayerView(AnimatedView* view) {
		this->view = view;
	}

	~PlayerView() {

	}

	/**
	 * @brief Gets the animated view associated with the player.
	 * @return A pointer to the player's animated view.
	 */
	AnimatedView* getView() {
		return view;
	}

};
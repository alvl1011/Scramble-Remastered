#pragma once

#include "ECS.h"
#include "AssetManager.h"
#include "TextureManager.h"
#include "Game.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>

/**
 * @class UILabel
 * @brief Represents a user interface (UI) label component for displaying text.
 *
 * The `UILabel` class is used to create text labels in a user interface for displaying textual information.
 */
class UILabel : public Component {

private:

	SDL_Rect position;
	std::string label_text;
	std::string label_font;
	SDL_Color text_color;
	SDL_Texture* label_texture;


public:

	/**
	 * @brief Constructor for UILabel with specified position, text content, font, and text color.
	 * @param xpos The X-coordinate of the label's position.
	 * @param ypos The Y-coordinate of the label's position.
	 * @param text The text content to display on the label.
	 * @param font The font style to use for the label's text.
	 * @param color The color of the label's text.
	 */
	UILabel(int xpos, int ypos, std::string text, std::string font, SDL_Color& color) :
		label_text(text), label_font(font), text_color(color)
	{
		position.x = xpos;
		position.y = ypos;

		SetLabelText(label_text, label_font);
	}

	~UILabel() { }

	/**
	* @brief Sets the text content and font style for the label.
	* @param text The new text content to display on the label.
	* @param font The new font style to use for the label's text.
	*/
	void SetLabelText(std::string text, std::string font) {
		SDL_Surface* surface = TTF_RenderText_Blended(Game::assets->GetFont(font), text.c_str(), text_color);
		label_texture = SDL_CreateTextureFromSurface(Game::renderer, surface);
		SDL_FreeSurface(surface);

		SDL_QueryTexture(label_texture, nullptr, nullptr, &position.w, &position.h);
	}

	/**
	* @brief Renders the label's text on the screen.
	*/
	void draw() override {
		SDL_RenderCopy(Game::renderer, label_texture, nullptr, &position);
	}

	/**
	 * @brief Gets a pointer to the position and size of the label.
	 * @return A pointer to the SDL_Rect representing the label's position and size.
	 */
	SDL_Rect* getPosition() {
		return &position;
	}
};

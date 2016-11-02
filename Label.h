#pragma once
#include <string>
#include "Style.h"
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "Font.h"

class Label : public Style
{
public:
	Label(std::string text, Font* font, int x, int y, int width, int height);



	/**
	* Render button on screen
	*/
	void render();


	/**
	* Set the font color for the button text.
	* Calling this will destroy and create a texture.
	* Do not call this often
	*/
	void setFontColor(int r, int g, int b, int a) override;

	void setFontSize(int size) override;

	void reloadTexture();

	void adjustDimensions()
	{
		TTF_SizeText(font->get(fontSize), text.c_str(), &dimensions.w, &dimensions.h);
	}

	~Label();

private:
	std::string text;
	Font* font;
	SDL_Texture* texture;
};

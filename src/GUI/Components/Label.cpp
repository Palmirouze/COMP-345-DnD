
#include <SDL/SDL.h>
#include "Label.h"

#include "../Renderer.h"

Label::Label(std::string text, Font* font, int x, int y, int width, int height) :Style(x, y, width, height), text(text), font(font)
{

	texture = Renderer::CreateTexture(text, font->get(fontSize), { 0,0,0,255 });
	setFontColor(255, 255, 255, 255);

}

void Label::render()
{
	int mx, my;

	SDL_GetMouseState(&mx, &my);
	bool hover = isInBounds(mx, my);

	drawDefaultStyle();

	Renderer::RenderTexture(texture, &dimensions);

	if (hover && fontUnderline_hover > 0)
	{
		Renderer::setColor(fontUnderlineColor_hover);
		Renderer::drawLine(dimensions.x, dimensions.y + dimensions.h, dimensions.x + dimensions.w, dimensions.y + dimensions.h);

	}
	else if (fontUnderline > 0)
	{
		Renderer::setColor(fontUnderlineColor);
		Renderer::drawLine(dimensions.x, dimensions.y + dimensions.h, dimensions.x + dimensions.w, dimensions.y + dimensions.h);
	}
}

void Label::setFontColor(int r, int g, int b, int a)
{
	Style::setFontColor(r, g, b, a);
	reloadTexture();
}

Label* Label::setFontSize(int size)
{
	Style::setFontSize(size);
	reloadTexture();
	return this;
}

void Label::reloadTexture()
{
	Renderer::destroyTexture(texture);
	texture = Renderer::CreateTexture(text, font->get(fontSize), fontColor);
}
std::string Label::getText()
{
	return text;
}

void Label::setText(std::string text)
{
	this->text = text;
	reloadTexture();
}

Label* Label::adjustDimensions()
{

	
		TTF_SizeText(font->get(fontSize), text.c_str(), &dimensions.w, &dimensions.h);

		return this;
	
}


Label::~Label()
{
	Renderer::destroyTexture(texture);
}

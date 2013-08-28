#include "stdafx.h"
#include "DebugOverlay.h"


DebugOverlay::DebugOverlay(void)
{
	font.loadFromFile("fonts/arial.ttf");
	visible = true;
}


DebugOverlay::~DebugOverlay(void)
{
}

void DebugOverlay::addString(std::string *string)
{
	strings.push_back(string);
}

void DebugOverlay::toggleVisible()
{
	visible = !visible;
}

void DebugOverlay::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if(visible)
	{
		for(unsigned int i=0; i < strings.size(); i++)
		{
			sf::Text text(*strings[i], font);
			text.setCharacterSize(FONT_SIZE);
			text.setPosition(0, ((FONT_SIZE + TEXT_MARGIN) * i));
			target.draw(text, states);
		}
	}
}

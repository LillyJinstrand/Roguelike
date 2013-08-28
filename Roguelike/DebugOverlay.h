#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
class DebugOverlay : public sf::Drawable
{
public:
	DebugOverlay(void);
	virtual ~DebugOverlay(void);
	void addString(std::string *string);
	void toggleVisible();
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	std::vector<std::string *> strings;
	sf::Font font;
	bool visible;

	static const int FONT_SIZE = 16;
	static const int TEXT_MARGIN = 1;
};


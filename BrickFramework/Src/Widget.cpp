#include "Widget.h"

namespace GUI
{
	Widget::Text::Text()
	{
		setCharacterSize(20);
		setOutlineColor(Color::Black);
		setFillColor(Color::White);
		//setFont();
	}

	bool Widget::Rectangle::isRolledOn(const RenderWindow& window) const
	{
		auto pos = Mouse::getPosition(window);
		return getGlobalBounds().contains((float)pos.x, (float)pos.y);
	}

	bool Widget::Rectangle::isClicked(Event e, const RenderWindow & window)
	{
		if (isRolledOn(window))
		{
			if (e.type == Event::MouseButtonPressed)
			{
				return e.mouseButton.button == Mouse::Left;
			}
		}

		return false;
	}

}

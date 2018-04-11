#pragma once
#include <SFML\Graphics.hpp>

using namespace sf;
namespace GUI
{
	class Widget
	{
	public:
		virtual void HandleEvent(Event e, const RenderWindow &window) = 0;
		virtual void Render(RenderTarget &renderer) = 0;
		virtual void SetPosition(const Vector2f &pos) = 0;
		virtual Vector2f GetSize() const = 0;
	protected:
		class Text : public sf::Text
		{
		public:
			Text();
		};

		class Rectangle : public RectangleShape
		{
		public:
			bool isRolledOn(const RenderWindow &window) const;
			bool isClicked(Event e, const RenderWindow &window);
		};

	};
}
#include "GUIButton.h"
#include <iostream>

using namespace std;

namespace GUI
{
	GUIButton::GUIButton(ButtonSize s)
	{
		arial.loadFromFile("Fonts/arial.ttf");
		button.setFillColor({ 52, 152, 219 });
		switch (s)
		{
		case GUI::Small:
			button.setSize({ 128, 64 });
			break;
		case GUI::Wide:
			button.setSize({ 256, 64 });
			break;
		}
		Rect<float> buttonSize = button.getLocalBounds();
		button.setOrigin(buttonSize.width / 2, buttonSize.height / 2);
	}

	void GUIButton::SetFunction(std::function<void(void)> func)
	{
		function = func;
	}

	bool GUIButton::isClicked(RenderWindow &window)
	{
		auto pos = Mouse::getPosition(window);

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (button.getGlobalBounds().contains((float)pos.x, (float)pos.y))
			{
				return true;
			}
		}
	}


	void GUIButton::SetText(const string & str)
	{
		text.setString(str);
		text.setFont(arial);
		text.setFillColor(Color::White);
		UpdateText();
	}

	void GUIButton::SetTexture(const Texture & tex)
	{
		button.setTexture(&tex);
	}

	void GUIButton::HandleEvent(Event e, const RenderWindow & window)
	{
		/*switch (e.type) {
		case Event::MouseButtonPressed:
			switch (e.mouseButton.button) {
			case Mouse::Left:
				if (button.getGlobalBounds().contains((float)pos.x, (float)pos.y)) {
					function;
				}

			default:
				break;
			}

		default:
			break;
		}*/
	}

	void GUIButton::Render(RenderTarget & renderer)
	{
		renderer.draw(button);
		renderer.draw(text);
	}

	void GUIButton::SetPosition(const Vector2f & pos)
	{
		position = pos;

		button.setPosition(position);
		text.setPosition(position);

		UpdateText();
	}

	Vector2f GUIButton::GetSize() const
	{
		return button.getSize();

	}

	void GUIButton::UpdateText()
	{
		text.setOrigin(text.getGlobalBounds().width / 2,
			text.getGlobalBounds().height / 2);

		/*text.move(button.getGlobalBounds().width / 2.0f,
			button.getGlobalBounds().height / 2.5f);*/
	}
}

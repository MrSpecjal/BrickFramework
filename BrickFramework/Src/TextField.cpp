#include "TextField.h"
using namespace std;

namespace GUI
{
	TextField::TextField(string & modString): pModString(&modString)
	{
		label.setCharacterSize(15);
		rect.setFillColor({ 52, 152, 219 });
		rect.setSize({ 256, 64 });
	}
	void TextField::SetLabel(const std::string & str)
	{
		label.setString(str);
	}
	void TextField::SetTexture(const Texture & tex)
	{

	}
	void TextField::HandleEvent(Event e, const RenderWindow & window)
	{
		HandleEvent(e, window);
		HandleTextInput(e);
	}
	void TextField::Render(RenderTarget & renderer)
	{
		if (!isActive)
		{
			rect.setFillColor({ 52, 152, 219 });
		}
		else
		{
			rect.setFillColor({ 82, 132, 239 });
		}

		renderer.draw(rect);
		renderer.draw(label);
		renderer.draw(text);
	}
	void TextField::SetPosition(const Vector2f & pos)
	{
		position = pos;
		rect.setPosition(position);
		label.setPosition(position.x, position.y + label.getGlobalBounds().height - label.getGlobalBounds().width / 2);
		text.setPosition(position);
		text.move(5, rect.getGlobalBounds().height / 2.5f);
	}
	Vector2f TextField::GetSize() const
	{
		return  { rect.getSize().x,
			rect.getSize().y + label.getGlobalBounds().height };
	}
	void TextField::HandleClick(Event e, const RenderWindow & window)
	{
		auto pos = Mouse::getPosition(window);

		if (rect.getGlobalBounds().contains((float)pos.x, (float)pos.y))
		{
			if (e.type == Event::MouseButtonPressed)
			{
				if (e.mouseButton.button == Mouse::Left)
				{
					isActive = true;
				}
			}
		}
		else
		{
			if (e.type == Event::MouseButtonPressed)
			{
				if (e.mouseButton.button == Mouse::Left)
				{
					isActive = false;
				}
			}
		}
	}
	void TextField::HandleTextInput(Event e)
	{
		switch (e.type) {
		case Event::TextEntered:
			if (isActive) {
				//Get the key that was entered
				unsigned char keyCode = e.text.unicode;

				if (isValidCharacter(keyCode)) {
					pModString->push_back(keyCode);
				}
				else if (isBackspace(keyCode)) {
					//prevents popping back an empty string
					if (pModString->length() > 0)
						pModString->pop_back();
				}
				text.setString(*pModString);
			}
			break;

		default:
			break;
		}


		if (e.type == Event::TextEntered && isActive)
		{
			//Get the key that was entered
			unsigned char keyCode = e.text.unicode;

			//Test if it within the "Type-able keys eg aA to zZ and 0 to 9
			if (isValidCharacter(keyCode))
			{
				pModString->push_back(keyCode);
			}
			else if (isBackspace(keyCode))
			{
				//prevents popping back an empty string
				if (pModString->length() > 0)
					pModString->pop_back();
			}
			text.setString(*pModString);
		}
	}
	bool TextField::isValidCharacter(unsigned char keyCode)
	{
		return false;
	}
	bool TextField::isBackspace(unsigned char keyCode)
	{
		return false;
	}
}
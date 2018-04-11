#pragma once
#include <functional>
#include "Widget.h"

using namespace std;

namespace GUI
{
	class TextField : public GUI::Widget
	{
	public:
		TextField(string &modString);

		void SetLabel(const string &str);
		void SetTexture(const Texture &tex);

		void HandleEvent(Event e, const RenderWindow &window) override;
		void Render(RenderTarget &renderer) override;
		void SetPosition(const Vector2f &pos) override;
		Vector2f GetSize() const override;

	private:
		void HandleClick(Event e, const RenderWindow &window);
		void HandleTextInput(Event e);

		bool isValidCharacter(unsigned char keyCode);
		bool isBackspace(unsigned char keyCode);

		Vector2f position;

		Rectangle rect;
		Text text;
		Text label;
		string* pModString;

		bool isActive = false;
	};

}


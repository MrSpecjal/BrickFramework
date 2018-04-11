#pragma once
#include "Widget.h"
#include "Game.h"
#include <functional>

using namespace std;

namespace GUI
{
	enum ButtonSize 
	{
		Small,
		Wide,
	};

	class GUIButton : Widget
	{
	public:
		GUIButton(ButtonSize s = ButtonSize::Wide);

		void SetFunction(function<void(void)> func);
		bool isClicked(RenderWindow &window);
		void SetText(const string& str);
		void SetTexture(const Texture& tex);

		void HandleEvent(Event e, const RenderWindow& window) override;
		void Render(RenderTarget& renderer) override;
		void SetPosition(const Vector2f& pos) override;
		Vector2f GetSize() const override;
		
	private:
		void UpdateText();
		Vector2f position;

		Rectangle button;
		Text text;
		Font arial;
		function<void(void)> function = []() {};
	};

}



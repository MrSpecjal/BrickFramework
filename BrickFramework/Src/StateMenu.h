#pragma once
#include "StateBase.h"
#include "GUIButton.h"

class StateMenu : public StateBase
{
public:
	StateMenu(Game &game);
	~StateMenu();

	void HandleEvent(Event e, RenderWindow &window) override;
	void HandleInput() override;
	void Update(Time deltaTime) override;
	void FixedUpdate(Time deltaTime) override;
	void Render(RenderTarget &renderer) override;

	GUI::GUIButton button;
};


#pragma once
#include "StateBase.h"
#include "GUIButton.h"

class StatePlaying : public StateBase
{
public:
	StatePlaying(Game &game);
	~StatePlaying();

	void HandleEvent(Event e, RenderWindow &window) override;
	void HandleInput() override;
	void Update(Time deltaTime) override;
	void FixedUpdate(Time deltaTime) override;
	void Render(RenderTarget &renderer) override;

	GUI::GUIButton button;
};


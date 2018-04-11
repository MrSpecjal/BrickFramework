#pragma once
#include <SFML\Graphics.hpp>

using namespace sf;

class Game;

class StateBase
{
public:
	StateBase(Game&game) :game(&game) {}
	virtual ~StateBase() = default;

	virtual void HandleEvent(Event e, RenderWindow &window) = 0;
	virtual void HandleInput() = 0;
	virtual void Update(Time deltaTime) = 0;
	virtual void FixedUpdate(Time deltaTime) = 0;
	virtual void Render(RenderTarget &renderer) = 0;

protected:
	Game *game;

};
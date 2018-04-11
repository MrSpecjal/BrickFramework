#pragma once
#include <memory>
#include <vector>
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include "StateBase.h"

using namespace sf;
using namespace std;

class Game
{
public:
	Game();

	void Run();
	template<typename T, typename... Args>
	void PushState(Args&&... args);

	void PopState();

	const RenderWindow &GetWindow() const;

private:
	void HandleEvent();
	void TryPop();

	StateBase &GetCurrentState();
	RenderWindow window;
	vector<unique_ptr<StateBase>> states;

	bool shouldPop = false;
};

template<typename T, typename... Args>
void Game::PushState(Args&&... args)
{
	states.push_back(make_unique<T>(forward<Args>(args)...));
}


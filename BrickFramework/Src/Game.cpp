#include <iostream>
#include "Game.h"
#include "StatePlaying.h"
#include "StateMenu.h"

Game::Game() : window({640, 480}, "Brick Framework")
{
	window.setFramerateLimit(60);
	PushState<StateMenu>(*this);
}

void Game::Run()
{
	std::cout << "Game is running\n";
	constexpr unsigned TPS = 60;
	const Time timePerUpdate = seconds(1 / float(TPS));
	unsigned ticks = 0;

	Clock timer;
	Time lastTime = Time::Zero;
	Time lag = Time::Zero;

	while (window.isOpen() && !states.empty())
	{
		auto &state = GetCurrentState();

		auto time = timer.getElapsedTime();
		auto elapsed = time - lastTime;

		lastTime = time;
		lag += elapsed;

		//Realtime update
		state.HandleInput();
		state.Update(elapsed);

		//Fixed time update	
		while (lag >= timePerUpdate)
		{
			ticks++;
			lag -= timePerUpdate;
			state.FixedUpdate(elapsed);
		}

		//cout << "Elapsed time: " << elapsed.asSeconds() << endl;

		window.clear(Color::White);
		state.Render(window);
		window.display();

		//Handle Window Events
		HandleEvent();
		TryPop();
	}
}

void Game::TryPop()
{
	if (shouldPop)
	{
		states.pop_back();
		PushState<StatePlaying>(*this); 
	}
}

//Handle window events, called every frame
void Game::HandleEvent()
{
	Event e;
	while (window.pollEvent(e))
	{
		GetCurrentState().HandleEvent(e, window);
		switch (e.type)
		{
			case Event::Closed:
				window.close();
				break;
		}
	}
}

StateBase &Game::GetCurrentState()
{
	return *states.back();
}

void Game::PopState()
{
	shouldPop = true;
}

const RenderWindow &Game::GetWindow() const
{
	return window;
}
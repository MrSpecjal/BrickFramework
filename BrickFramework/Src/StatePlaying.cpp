#include "StatePlaying.h"
#include "Game.h"
#include "GUIButton.h"
#include "TextField.h"
#include "GameObject.h"
#include <iostream>

using namespace std;


StatePlaying::StatePlaying(Game & game) : StateBase(game)
{
	button.SetText("I'm in a game!");
	button.SetPosition({ 320, 140 });
}

StatePlaying::~StatePlaying()
{
}

void StatePlaying::HandleEvent(Event e, RenderWindow &window)
{
	if (button.isClicked(window))
	{
		cout << "I'm working YAY \n";
	}
}

void StatePlaying::HandleInput()
{
}

void StatePlaying::Update(Time deltaTime)
{
	cout << "Current state: StatePlaying\n";
}

void StatePlaying::FixedUpdate(Time deltaTime)
{
}

void StatePlaying::Render(RenderTarget & renderer)
{
	//cout << "rendering...\n";
	button.Render(renderer);
	//cout << "rendered\n";
}

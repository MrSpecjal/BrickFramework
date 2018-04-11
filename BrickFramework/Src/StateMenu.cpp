#include "StateMenu.h"
#include "Game.h"
#include "GUIButton.h"
#include "TextField.h"
#include "GameObject.h"
#include "StatePlaying.h"
#include <iostream>

using namespace std;

StateMenu::StateMenu(Game & game) : StateBase(game)
{
	button.SetText("Play!");
	button.SetPosition({ 320, 240 });
}

StateMenu::~StateMenu()
{

}

void StateMenu::HandleEvent(Event e, RenderWindow &window)
{
	if (button.isClicked(window))
	{
		game->PopState();
		//game->PushState<StatePlaying>();
	}
}

void StateMenu::HandleInput()
{

}

void StateMenu::Update(Time deltaTime)
{
	cout << "Current state: MenuState \n";
}

void StateMenu::FixedUpdate(Time deltaTime)
{
}

void StateMenu::Render(RenderTarget & renderer)
{
	button.Render(renderer);
}

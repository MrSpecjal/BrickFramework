#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>	
#include "Collider.h"

using namespace sf;
class GameObject
{
public:
	GameObject(Texture *texture);
	
	void Render(RenderWindow &window);
	void OnCollision(Vector2f direction);

	Vector2f GetPosition() { return body.getPosition(); }
	Collider GetCollider() { return Collider(body); }
private:
	RectangleShape body;

};


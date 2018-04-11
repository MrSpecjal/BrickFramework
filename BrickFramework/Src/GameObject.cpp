#include "GameObject.h"

GameObject::GameObject(Texture * texture)
{
	body.setOrigin(body.getSize().x / 2, body.getSize().y / 2);
	body.setTexture(texture);
}

void GameObject::Render(RenderWindow & window)
{
	window.draw(body);
}

void GameObject::OnCollision(Vector2f direction)
{
}

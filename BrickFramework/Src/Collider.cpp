#include "Collider.h"

Collider::Collider(RectangleShape &body) :
	body(body)
{

}

Collider::~Collider()
{
}

bool Collider::CheckCollision(Collider &other, Vector2f &direction, float push)
{
	Vector2f otherPosition = other.GetPosition();
	Vector2f otherHalfSize = other.GetHalfSize();
	Vector2f thisPosition = GetPosition();
	Vector2f thisHalfSize = GetHalfSize();

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;
	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

	if (intersectX < 0.0f && intersectY < 0.0f)
	{
		push = std::min(std::max(push, 0.0f), 1.0f);

		if (intersectX > intersectY)
		{
			if (deltaX > 0.0f)
			{
				Move(intersectX * (1.0f - push), 0.0f);
				other.Move(-intersectX * (1.0f - push), 0.0f);

				direction.x = 1;
				direction.y = 0;
			}
			else
			{
				Move(-intersectX * (1.0f - push), 0.0f);
				other.Move(intersectX * (1.0f - push), 0.0f);

				direction.x = -1;
				direction.y = 0;
			}
		}
		else
		{
			if (deltaY > 0.0f)
			{
				Move(0.0f, intersectY * (1.0f - push));
				other.Move(0.0f, -intersectY * (1.0f - push));

				direction.x = 0;
				direction.y = 1;
			}
			else
			{
				Move(0.0f, -intersectY * (1.0f - push));
				other.Move(0.0f, intersectY * (1.0f - push));

				direction.x = 0;
				direction.y = -1;
			}
		}

		return true;
	}
	return false;
}

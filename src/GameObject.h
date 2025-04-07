#pragma once
#include "raylib.h"

namespace SnakeRay
{
	class GameObject
	{
	public:
		virtual ~GameObject() {};

		virtual void Update(float deltaTime) = 0;
		virtual void Draw() = 0;

	protected:
		Vector2 Position{};
	};
};

#pragma once
#include "raylib.h"

namespace SnakeRay
{
	class GameObject
	{
	public:
		GameObject(int cellSize);
		virtual ~GameObject() {};

		virtual void Update(float deltaTime) = 0;
		virtual void Draw() = 0;

		Vector2 GetPosition() const { return Position; }

	protected:
		float LastUpdateTime = 0;

		int CellSize{};
		Vector2 Position{};
	};
};

#pragma once
#include "GameObject.h"
#include <deque>

namespace SnakeRay
{
	class Snake : public GameObject
	{
	public:
		Snake(int cellSize);
		~Snake() override;

		void Update(float deltaTime) override;
		void Draw() override;

	private:
		Vector2 GetHead();
		Vector2 GetTail();

	private:
		int _cellSize = 0;

		Vector2 _direction = { 1,0 };
		std::deque<Vector2> _body;

		float _lastUpdateTime = 0;

	};
}

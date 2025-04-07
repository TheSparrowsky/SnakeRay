#pragma once
#include "GameObject.h"

namespace SnakeRay
{
	class Food : public GameObject
	{
	public:
		Food(int cellSize);
		~Food() override;

		void Update(float deltaTime) override;
		void Draw() override;
	private:
		Rectangle _rectangle;

		float _currentCellSize = 0;
		float _animationDirection = .5f;
	};
}

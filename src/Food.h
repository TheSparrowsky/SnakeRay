#pragma once
#include "GameObject.h"
#include "Game.h"

namespace SnakeRay
{
	class Food : public GameObject
	{
	public:
		Food(Game& game);
		~Food() override;

		void Update(float deltaTime) override;
		void Draw() override;

		void Reset();
	private:
		Game& _game;
		Rectangle _rectangle;

		float _currentCellSize = 0;
		float _animationDirection = .5f;
	};
}

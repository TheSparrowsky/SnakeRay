#pragma once
#include "Game.h"
#include "GameObject.h"
#include <deque>

namespace SnakeRay
{
	class Food;
	class PlaygroundFrame;
	class Snake : public GameObject
	{
	public:
		Snake(Game& game);
		~Snake() override;

		bool IsCollidingWithFood(const Food& food);
		bool IsCollidingWithFrame(const PlaygroundFrame& frame);
		bool IsCollidingWithItself();
		void Grow();
		void Reset();

		void Update(float deltaTime) override;
		void Draw() override;

	private:
		Vector2 GetHead();
		Vector2 GetTail();


	private:
		Game& _game;
		Vector2 _direction = { 1,0 };
		std::deque<Vector2> _body;

		bool _selfCollides = false;
	};
}

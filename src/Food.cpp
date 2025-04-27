#include "Food.h"

namespace SnakeRay
{
	Food::Food(Game& game)
		: _game(game), GameObject(game.Options.CellSize)
	{
		_currentCellSize = CellSize; 
		Reset();
	}
	Food::~Food()
	{

	}

	void Food::Reset()
	{
		float x = GetRandomValue(_game.Options.FrameOffset / _game.Options.CellSize, (_game.Options.FrameOffset / _game.Options.CellSize) + (_game.Options.PlaygroundSize / _game.Options.CellSize) - 1); // 0,48 + frameOffset ( - frame border width for y) - fixed values, temporary
		float y = GetRandomValue(_game.Options.FrameOffset / _game.Options.CellSize, (_game.Options.FrameOffset / _game.Options.CellSize) + (_game.Options.PlaygroundSize / _game.Options.CellSize) - 1); // =||=
		Position = Vector2{ x, y};
		_rectangle = Rectangle{ Position.x * CellSize, Position.y * CellSize, (float)CellSize, (float)CellSize };
	}

	void Food::Update(float deltaTime) 
	{
		//LastUpdateTime += deltaTime;

		//if (LastUpdateTime >= 0.12f)
		//{
		//	LastUpdateTime = 0;

		//	_currentCellSize = _currentCellSize * _animationDirection;
		//	_rectangle = Rectangle{ Position.x * CellSize + _currentCellSize, Position.y * CellSize + _currentCellSize, _currentCellSize, _currentCellSize };
		//	
		//	if (_animationDirection == 2)
		//		_animationDirection /= 4;
		//	else
		//		_animationDirection *= 4;
		//}
	}

	void Food::Draw()
	{
		DrawRectangleRounded(_rectangle, .4f, 4, Theme::FoodColor);
	}
}
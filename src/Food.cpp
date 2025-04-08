#include "Food.h"

namespace SnakeRay
{
	Food::Food(int cellSize)
		: GameObject(cellSize)
	{
		_currentCellSize = CellSize; 
		Reset();
	}
	Food::~Food()
	{

	}

	void Food::Reset()
	{
		float x = GetRandomValue(0, 48);
		float y = GetRandomValue(0, 48);
		Position = Vector2{ x, y };
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
		DrawRectangleRounded(_rectangle, .4f, 4, Color{ 238,78,78,255 });
	}
}
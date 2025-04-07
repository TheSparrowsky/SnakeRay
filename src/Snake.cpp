#include "Snake.h"
#include "raymath.h"

namespace SnakeRay
{
	Snake::Snake(int cellSize)
		: _cellSize(cellSize)
	{
		_body = std::deque<Vector2>{ Vector2{7, 5}, Vector2{6,5}, Vector2{8,5} };
	}

	Snake::~Snake()
	{

	}

	void Snake::Update(float deltaTime)
	{
		_lastUpdateTime += deltaTime;

		if ((IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)) && _direction.x != -1)
			_direction = Vector2{ 1, 0 };
		if ((IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT)) && _direction.x != 1)
			_direction = Vector2{ -1, 0 };
		if ((IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) && _direction.y != 1)
			_direction = Vector2{ 0, -1 };
		if ((IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)) && _direction.y != -1)
			_direction = Vector2{ 0, 1 };

		if (_lastUpdateTime >= 0.12f)
		{
			_lastUpdateTime = 0;
			
			// move
			Vector2 head = GetHead();

			_body.pop_back();
			_body.push_front(Vector2Add(head, _direction));
		}
	}

	void Snake::Draw()
	{
		for (size_t i = 0; i < _body.size(); i++)
		{
			Rectangle rec = Rectangle{ _body[i].x * _cellSize, _body[i].y * _cellSize, (float)_cellSize, (float)_cellSize };
			DrawRectangleRounded(rec, .4f, 4, Color{121,147,81,255});
		}
	}

	Vector2 Snake::GetHead()
	{
		return _body[0];
	}
	
	Vector2 Snake::GetTail()
	{
		return _body[_body.size() - 1];
	}
}
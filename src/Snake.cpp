#include "Snake.h"
#include "raymath.h"
#include "Food.h"
#include "PlaygroundFrame.h"

namespace SnakeRay
{
	Snake::Snake(Game& game)
		: _game(game), GameObject(game.Options.CellSize)
	{
		Reset();
	}

	Snake::~Snake()
	{

	}

	void Snake::Update(float deltaTime)
	{
		LastUpdateTime += deltaTime;

		if ((IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)) && _direction.x != -1)
			_direction = Vector2{ 1, 0 };
		if ((IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT)) && _direction.x != 1)
			_direction = Vector2{ -1, 0 };
		if ((IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) && _direction.y != 1)
			_direction = Vector2{ 0, -1 };
		if ((IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)) && _direction.y != -1)
			_direction = Vector2{ 0, 1 };

		if (LastUpdateTime >= 0.12f)
		{
			LastUpdateTime = 0;
			
			// move
			
			Vector2 head = GetHead();

			auto moveVector = Vector2Add(head, _direction);
			if (std::find(_body.begin(), _body.end(), moveVector) != _body.end())
			{
				Reset();
			}
			else 
			{
				_body.pop_back();
				_body.push_front(moveVector);
			}
		}
	}

	void Snake::Draw()
	{
		for (size_t i = 0; i < _body.size(); i++)
		{
			Rectangle rec = Rectangle{ _body[i].x * CellSize, _body[i].y * CellSize, (float)CellSize, (float)CellSize };
			DrawRectangleRounded(rec, .4f, 4, Color{121,147,81,255});
		}
	}

	void Snake::Grow()
	{
		Vector2 head = GetHead();
		_body.push_front(Vector2Add(head, _direction));
	}

	bool Snake::IsCollidingWithFood(const Food& food)
	{
		if (Vector2Subtract(GetHead(), food.GetPosition()) == Vector2{})
		{
			return true;
		}

		return false;
	}

	bool Snake::IsCollidingWithFrame(const PlaygroundFrame& frame)
	{
		auto head = GetHead();
		auto framePosition = frame.GetPosition();

		float headX = head.x * CellSize;
		float headY = head.y * CellSize;
		return headX <= framePosition.x || headY <= framePosition.y
			|| headX >= framePosition.x + frame.GetWidth() || headY >= framePosition.y + frame.GetHeight();
	}

	void Snake::Reset()
	{
		float y = (_game.Options.FrameOffset / _game.Options.CellSize) + 5;
		float x = (_game.Options.FrameOffset / _game.Options.CellSize) + 5;
		_body = std::deque<Vector2>{ 
			Vector2{x + 3, y}, 
			Vector2{x + 2, y}, 
			Vector2{x + 1, y} 
		};
		_direction = { 1, 0 };
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
#include "Game.h"
#include "raylib.h"

#include "Snake.h" // temporary ?
#include "Food.h" // temporary ?
#include "PlaygroundFrame.h" // temporary ?

namespace SnakeRay
{
	Game::Game(const GameOptions& options)
		: _gameOptions(options)
	{
	}

	Game::~Game()
	{
	}

	void Game::Run()
	{
		InitWindow(_gameOptions.ScreenWidth + (2 * _gameOptions.FrameOffset), _gameOptions.ScreenHeight + (2 * _gameOptions.FrameOffset), _gameOptions.Title.c_str());
		SetTargetFPS(60);

		auto snake = std::make_shared<Snake>(_gameOptions.CellSize); // temporary
		auto food = std::make_shared<Food>(_gameOptions.CellSize); // temporary
		auto playgroundFrame = std::make_shared<PlaygroundFrame>(PlaygroundProperty{ _gameOptions.FrameOffset, _gameOptions.FrameOffset, (float)_gameOptions.ScreenWidth, (float)_gameOptions.ScreenHeight, 5 }, _gameOptions.CellSize); // temporary
		AddObject(snake);
		AddObject(food);
		AddObject(playgroundFrame);

		while (!WindowShouldClose())
		{
			auto deltaTime = GetFrameTime();
			BeginDrawing();
			ClearBackground(Color{ 161,221,112,255 });

			if (snake->IsCollidingWithFood(*food)) // temporary collision detection
			{
				food->Reset();
				snake->Grow();
			}

			if (snake->IsCollidingWithFrame(*playgroundFrame))
			{
				snake->Reset();
				food->Reset();
			}

			for (size_t i = 0; i < _gameObjects.size(); i++)
			{
				_gameObjects[i]->Update(deltaTime);

			}
			
			for (size_t i = 0; i < _gameObjects.size(); i++)
			{
				_gameObjects[i]->Draw();
			}

			EndDrawing();
		}

		CloseWindow();
	}

	void Game::AddObject(std::shared_ptr<GameObject> gameObject)
	{
		_gameObjects.push_back(gameObject);
	}
}
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
		int realWindowWidth = _gameOptions.ScreenWidth + (2 * _gameOptions.FrameOffset);
		int realWindowHeight = _gameOptions.ScreenHeight + (2 * _gameOptions.FrameOffset);

		InitWindow(realWindowWidth, realWindowHeight, _gameOptions.Title.c_str());
		SetTargetFPS(60);

		auto snake = std::make_shared<Snake>(_gameOptions.CellSize); // temporary
		auto food = std::make_shared<Food>(_gameOptions.CellSize); // temporary
		auto playgroundFrame = std::make_shared<PlaygroundFrame>(PlaygroundProperty{ _gameOptions.FrameOffset, _gameOptions.FrameOffset, (float)_gameOptions.ScreenWidth, (float)_gameOptions.ScreenHeight, 5 }, _gameOptions.CellSize); // temporary
		AddObject(snake);
		AddObject(food);
		AddObject(playgroundFrame);

		int score = 0;

		while (!WindowShouldClose())
		{
			auto deltaTime = GetFrameTime();
			BeginDrawing();
			ClearBackground(Color{ 161,221,112,255 });

			if (snake->IsCollidingWithFood(*food)) // temporary collision detection
			{
				food->Reset();
				snake->Grow();
				score++;
			}

			if (snake->IsCollidingWithFrame(*playgroundFrame))
			{
				snake->Reset();
				food->Reset();
				score = 0;
			}

			for (size_t i = 0; i < _gameObjects.size(); i++)
			{
				_gameObjects[i]->Update(deltaTime);
			}
			
			for (size_t i = 0; i < _gameObjects.size(); i++)
			{
				_gameObjects[i]->Draw();
			}

			// TODO: magic numbers problem
			DrawText(("Score: " + std::to_string(score)).c_str(), _gameOptions.FrameOffset, _gameOptions.FrameOffset - 50, 40, Color{246,238,201,255});
			DrawText("SnakeRay", realWindowWidth / 2 - (30 * 4), _gameOptions.ScreenHeight + _gameOptions.FrameOffset + 10, 40, Color{ 246,238,201,255 });

			EndDrawing();
		}

		CloseWindow();
	}

	void Game::AddObject(std::shared_ptr<GameObject> gameObject)
	{
		_gameObjects.push_back(gameObject);
	}
}
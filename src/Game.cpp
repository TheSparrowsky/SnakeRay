#include "Game.h"
#include "raylib.h"

#include "GamePlayScene.h"

namespace SnakeRay
{
	Game::Game(const GameOptions& options)
		: _gameOptions(options)
	{
		int realWindowWidth = _gameOptions.ScreenWidth + (2 * _gameOptions.FrameOffset);
		int realWindowHeight = _gameOptions.ScreenHeight + (2 * _gameOptions.FrameOffset);

		InitWindow(realWindowWidth, realWindowHeight, _gameOptions.Title.c_str());
		InitAudioDevice();
		SetTargetFPS(60);

		_currentScene = std::make_shared<GamePlayScene>(options);
	}

	Game::~Game()
	{
		CloseAudioDevice();
		CloseWindow();
	}

	void Game::Run()
	{
		while (!WindowShouldClose())
		{
			auto deltaTime = GetFrameTime();
			BeginDrawing();

			_currentScene->Update(deltaTime);
			
			_currentScene->Draw();

			EndDrawing();
		}
	}
}
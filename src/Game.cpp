#include "Game.h"
#include "raylib.h"

#include "GamePlayScene.h"
#include "MainMenuScene.h"

namespace SnakeRay
{
	Game::Game(const GameOptions& options)
		: Options(options)
	{
		int realWindowWidth = Options.ScreenWidth + (2 * Options.FrameOffset);
		int realWindowHeight = Options.ScreenHeight + (2 * Options.FrameOffset);

		InitWindow(realWindowWidth, realWindowHeight, Options.Title.c_str());
		InitAudioDevice();
		SetTargetFPS(60);

		//_currentScene = std::make_shared<GamePlayScene>(options);
		_currentScene = std::make_unique<MainMenuScene>(this);
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

	void Game::ChangeScene(std::unique_ptr<GameScene> newScene)
	{
		_currentScene = std::move(newScene);
	}
}
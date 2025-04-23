#include "Game.h"
#include "raylib.h"

#include "GamePlayScene.h"
#include "MainMenuScene.h"

namespace SnakeRay
{
	Game::Game(const GameOptions& options)
		: Options(options)
	{
		GameSceneManager = SceneManager();

		int realWindowWidth = Options.ScreenWidth + (2 * Options.FrameOffset);
		int realWindowHeight = Options.ScreenHeight + (2 * Options.FrameOffset);

		InitWindow(realWindowWidth, realWindowHeight, Options.Title.c_str());
		InitAudioDevice();
		SetTargetFPS(60);
		SetExitKey(0);

		//_currentScene = std::make_shared<GamePlayScene>(options);
		_currentScene = GameSceneManager.CreateScene<MainMenuScene>(this);
		// todo: what if currentscene is nullptr?
	}

	Game::~Game()
	{
		CloseAudioDevice();
		CloseWindow();
	}

	void Game::Run()
	{
		while (!_shouldExit)
		{
			_shouldExit = WindowShouldClose();
			auto deltaTime = GetFrameTime();
			BeginDrawing();

			_currentScene->Update(deltaTime);
			
			_currentScene->Draw();

			EndDrawing();
		}
	}

	void Game::Exit()
	{
		_shouldExit = true;
	}

	void Game::ChangeScene(std::shared_ptr<GameScene> newScene)
	{
		_currentScene = std::move(newScene);
	}
}
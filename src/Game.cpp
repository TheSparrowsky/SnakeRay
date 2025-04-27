#include "Game.h"
#include "raylib.h"

#include "GamePlayScene.h"
#include "Menu/MainMenu.h"

namespace SnakeRay
{
	Game::Game(const GameOptions& options)
		: Options(options)
	{
		InitWindow(Options.ScreenWidth, Options.ScreenHeight, Options.Title.c_str());
		InitAudioDevice();
		SetTargetFPS(60);
		SetExitKey(0);

		ChangeScene<MainMenu>();
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
}
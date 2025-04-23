#pragma once
#include <string>
#include <vector>
#include <memory>
#include "GameObject.h"
#include "GameScene.h"
#include "SceneManager.h"

namespace SnakeRay
{
	struct GameOptions
	{
		int ScreenWidth = 768;
		int ScreenHeight = 768;
		std::string Title = "SnakeRay";

		int CellSize = 16;
		float FrameOffset = 64;
	};

	class Game
	{
	public:
		Game(const GameOptions& options = GameOptions());
		~Game();

		void Run();
		void ChangeScene(std::shared_ptr<GameScene> newScene);

		void Exit();
		
		GameOptions Options;
		SceneManager GameSceneManager;
	private:
		bool _shouldExit = false;
		std::shared_ptr<GameScene> _currentScene;
	};
};
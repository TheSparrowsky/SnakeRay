#pragma once
#include <string>
#include <vector>
#include <memory>
#include "GameObject.h"
#include "GameScene.h"

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
		void ChangeScene(std::unique_ptr<GameScene> newScene);
		
		GameOptions Options;
	private:

		std::unique_ptr<GameScene> _currentScene;
	};
};
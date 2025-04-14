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
	private:
		GameOptions _gameOptions;

		std::shared_ptr<GameScene> _currentScene;
	};
};
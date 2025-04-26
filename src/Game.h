#pragma once
#include <string>
#include <vector>
#include <memory>
#include "GameObject.h"
#include "GameScene.h"

#include "Menu/MainMenu.h"
namespace SnakeRay
{
	struct GameOptions
	{
		int ScreenWidth = 768;
		int ScreenHeight = 768;
		std::string Title = "SnakeRay";


		int CellSize = 16;
		int PlaygroundSize = CellSize * 40;

		float FrameOffset = 64;
	};

	class Game
	{
	public:
		Game(const GameOptions& options = GameOptions());
		~Game();

		void Run();
		void Exit();
		
		template<typename T>
		void ChangeScene()
		{
			_currentScene = std::make_shared<T>(*this);
			_currentScene->OnLoad();
		}

	public:
		GameOptions Options;
		enum DifficultyLevel { EASY = 0, MEDIUM = 1, HARD = 2};
		DifficultyLevel CurrentDifficulty = DifficultyLevel::EASY;

		void SetDifficulty(DifficultyLevel level) { CurrentDifficulty = level; }

	private:
		bool _shouldExit = false;
		std::shared_ptr<GameScene> _currentScene;

	};
};
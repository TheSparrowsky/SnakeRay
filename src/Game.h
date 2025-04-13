#pragma once
#include <string>
#include <vector>
#include <memory>
#include "GameObject.h"

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
		using GameObjectList = std::vector<std::shared_ptr<GameObject>>;

		Game(const GameOptions& options = GameOptions());
		~Game();

		void Run();
	private:
		void AddObject(std::shared_ptr<GameObject> gameObject);

		GameOptions _gameOptions;
		GameObjectList _gameObjects;
	};
};
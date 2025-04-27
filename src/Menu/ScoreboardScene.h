#pragma once
#include "GameScene.h"
#include <string>
#include <map>
#include <vector>

#include "Globals.h"
#include "Game.h"

namespace SnakeRay
{
	using namespace SnakeRay::Types;
	class ScoreboardScene : public GameScene
	{
	public:
		ScoreboardScene(Game& game);
		~ScoreboardScene();

		bool OnLoad() override;
		void Update(float deltaTime) override;
		void Draw() override;

	private:
		Scoreboard _scoreboard;
		int _beforeSelectedDifficultyIndex = 0;
		int _selectedDifficultyIndex = 0;
	};
}
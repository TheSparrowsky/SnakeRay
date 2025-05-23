#pragma once
#include <array>
#include "../Game.h"
#include "../GameScene.h"

#include "DifficultySelectionMenu.h"
#include "ScoreboardScene.h"
namespace SnakeRay
{
	class MainMenu : public GameScene
	{
	public:
		MainMenu(Game& game);

		bool OnLoad() override { return true; }
		void Update(float deltaTime) override;
		void Draw() override;

	private:
		std::array<const char*, 3> _options = { "Play", "Scoreboard", "Exit" };
		int _currentSelectedIndex = 0;
	};
}
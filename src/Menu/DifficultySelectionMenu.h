#pragma once
#include "../Game.h"
#include "../GameScene.h"
#include "MainMenu.h"
#include "../GamePlayScene.h"

#include <array>
namespace SnakeRay
{
	class DifficultySelectionMenu : public GameScene
	{
	public:
		DifficultySelectionMenu(Game& game);

		bool OnLoad() override { return true; }
		void Update(float deltaTime) override;
		void Draw() override;

	private:
		std::array<const char*, 4> _options = { "Easy", "Medium", "Hard", "Back"};
		int _currentSelectedIndex = 0;

		Color _foreColor = Color{ 246,238,201,255 };
	};
}
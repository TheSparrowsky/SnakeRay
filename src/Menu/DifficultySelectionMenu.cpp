#include "DifficultySelectionMenu.h"

namespace SnakeRay
{
	DifficultySelectionMenu::DifficultySelectionMenu(Game& game)
		: GameScene(game)
	{ }

	
	void DifficultySelectionMenu::Update(float deltaTime)
	{
		if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP))
			_currentSelectedIndex--;
		else if (IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN))
			_currentSelectedIndex++;

		if (_currentSelectedIndex < 0)
			_currentSelectedIndex = _options.size() - 1;
		else if (_currentSelectedIndex > _options.size() - 1)
			_currentSelectedIndex = 0;

		if (IsKeyPressed(KEY_ENTER))
		{
			if (_currentSelectedIndex >= 0 && _currentSelectedIndex <= 2) // difficulty level
			{
				_Game.SetDifficulty(static_cast<Game::DifficultyLevel>(_currentSelectedIndex));
				_Game.ChangeScene<GamePlayScene>();
			}
			else if (_currentSelectedIndex == 3)
			{
				_Game.ChangeScene<MainMenu>();
			}
		}
	}

	void DifficultySelectionMenu::Draw()
	{
		auto gameOptions = _Game.Options;
		ClearBackground(Color{ 161,221,112,255 }); // same in GamePlayScene

		DrawText("SnakeRay", gameOptions.ScreenWidth / 2, 64, 40, _foreColor);

		for (size_t i = 0; i < _options.size(); i++)
		{
			int rowOffsetMultiplier = i;
			if (i == 3) // exit
			{
				rowOffsetMultiplier = 2 * i;
			}

			DrawText(_options[i], gameOptions.ScreenWidth / 2.f, 128 + (40 * rowOffsetMultiplier), 40, _foreColor);
			if (_currentSelectedIndex == i)
			{
				DrawText(">", gameOptions.ScreenWidth / 2.f - 40, 128 + (40 * rowOffsetMultiplier), 40, _foreColor);
			}
		}
	}
}
#include "MainMenu.h"

namespace SnakeRay
{
	MainMenu::MainMenu(Game& game)
		: GameScene(game)
	{
	}

	void MainMenu::Update(float deltaTime)
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
			if (_currentSelectedIndex == 0) // Play
			{
				_Game.ChangeScene<DifficultySelectionMenu>();
			}
			else if (_currentSelectedIndex == 1) // scoreboard
			{
				_Game.ChangeScene<ScoreboardScene>();
			}
			else if (_currentSelectedIndex == 2) // exit
			{
				_Game.Exit();
			}
		}

	}

	void MainMenu::Draw() 
	{
		auto gameOptions = _Game.Options;
		ClearBackground(Theme::BackgroundColor); // same in GamePlayScene
		
		DrawText("SnakeRay", gameOptions.ScreenWidth / 2, 64, 40, Theme::ForeColor);

		for (size_t i = 0; i < _options.size(); i++)
		{
			DrawText(_options[i], gameOptions.ScreenWidth / 2.f, 128 + (40 * i), 40, Theme::ForeColor);
			if (_currentSelectedIndex == i)
			{
				DrawText(">", gameOptions.ScreenWidth / 2.f - 40, 128 + (40 * i), 40, Theme::ForeColor);
			}
		}

	}
}
#include "GameOverMenu.h"

namespace SnakeRay
{
	GameOverMenu::GameOverMenu(Game& game)
		: GameScene(game)
	{
		_textBox = Rectangle{ game.Options.ScreenWidth / 2.f - 200, 180, 225, 50 };
		_scores = game._ScoreManager.GetScore();
	}

	void GameOverMenu::Update(float deltaTime)
	{
		if (IsKeyPressed(KEY_ENTER))
		{
			_Game.ChangeScene<MainMenu>();
			return;
		}

		int key = GetCharPressed();
		while (key > 0)
		{
			if (((key >= 65 && key <= 90) || key >= 97 && key <= 122) && (_name.length() < _maxChars))
			{
				_name.push_back((char)toupper(key));
			}

			key = GetCharPressed();
		}

		if (IsKeyPressed(KEY_BACKSPACE) && _name.length() > 0)
		{
			_name.pop_back();
		}

		_frameCounter++;
	}

	void GameOverMenu::Draw()
	{
		ClearBackground(Theme::BackgroundColor); // same in GamePlayScene

		DrawText(("You scored " + std::to_string(_scores) + " points!").c_str(), _Game.Options.ScreenWidth / 2.f - 200, 90, 40, Theme::ForeColor);
		DrawText(_infoText, _Game.Options.ScreenWidth / 2.f - 200, 130, 40, Theme::ForeColor);
		DrawRectangleLines((int)_textBox.x, (int)_textBox.y, (int)_textBox.width, (int)_textBox.height, Theme::ForeColor);
		DrawText(_name.c_str(), (int)_textBox.x + 5, (int)_textBox.y + 8, 40, Theme::ForeColor);

		if (_name.length() < _maxChars)
		{
			if ((_frameCounter / 20) % 2 == 0)
				DrawText("_", (int)_textBox.x + 8 + MeasureText(_name.c_str(), 40), (int)_textBox.y + 12, 40, Theme::ForeColor);
		}

		DrawText("Press ENTER to continue...", _Game.Options.ScreenWidth / 2.f - 200, 230, 40, Theme::ForeColor);
	}
	
}
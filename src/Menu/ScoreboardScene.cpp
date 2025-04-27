#include "ScoreboardScene.h"

namespace SnakeRay
{
	ScoreboardScene::ScoreboardScene(Game& game)
		: GameScene(game)
	{
	}

	ScoreboardScene::~ScoreboardScene()
	{
	}

	bool ScoreboardScene::OnLoad()
	{
		_scoreboard = _Game._ScoreManager.GetScoreboard();
		return true;
	}

	void ScoreboardScene::Update(float deltaTime)
	{
		if (IsKeyPressed(KEY_ESCAPE))
		{
			_Game.ChangeScene<MainMenu>();
			return;
		}

		_beforeSelectedDifficultyIndex = _selectedDifficultyIndex;
		if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT))
			_selectedDifficultyIndex--;
		else if (IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT))
			_selectedDifficultyIndex++;

		if (_selectedDifficultyIndex < 0)
			_selectedDifficultyIndex = 2;
		else if (_selectedDifficultyIndex > 2)
			_selectedDifficultyIndex = 0;

		if (_beforeSelectedDifficultyIndex != _selectedDifficultyIndex)
		{
			_scoreboard = _Game._ScoreManager.GetScoreboard();
		}
	}

	void ScoreboardScene::Draw()
	{
		ClearBackground(Theme::BackgroundColor); // same in GamePlayScene
		
		DrawText("Scores", _Game.Options.ScreenWidth / 2.f - 50, 20, 40, Theme::ForeColor);

		DrawText("Easy", _Game.Options.ScreenWidth / 2.f - 300, 80, 40, Theme::ForeColor);
		DrawText("Medium", _Game.Options.ScreenWidth / 2.f - 50, 80, 40, Theme::ForeColor);
		DrawText("Hard", _Game.Options.ScreenWidth / 2.f + 200, 80, 40, Theme::ForeColor);

		Vector2 startPos{};
		Vector2 endPos{};
		if (_selectedDifficultyIndex == 0)
		{
			startPos.x = _Game.Options.ScreenWidth / 2.f - 300;
			startPos.y = 125;

			endPos.x = _Game.Options.ScreenWidth / 2.f - 200;
			endPos.y = 125;
		}
		else if(_selectedDifficultyIndex == 1)
		{
			startPos.x = _Game.Options.ScreenWidth / 2.f - 50;
			startPos.y = 125;

			endPos.x = _Game.Options.ScreenWidth / 2.f + 80;
			endPos.y = 125;
		}
		else
		{
			startPos.x = _Game.Options.ScreenWidth / 2.f + 200;
			startPos.y = 125;

			endPos.x = _Game.Options.ScreenWidth / 2.f + 300;
			endPos.y = 125;
		}

		DrawLineEx(startPos, endPos, 5, Theme::ForeColor);

		DrawText("Player", _Game.Options.ScreenWidth / 2.f - 200, 180, 40, Theme::ForeColor);
		DrawText("Score", _Game.Options.ScreenWidth / 2.f + 100, 180, 40, Theme::ForeColor);


		for (int i = 0; i < 10; i++)
		{
			std::string playerName = "...";
			std::string score = "...";

			if (_scoreboard[_selectedDifficultyIndex].size() >= i + 1)
			{
				playerName = _scoreboard[_selectedDifficultyIndex][i].Name;
				score = _scoreboard[_selectedDifficultyIndex][i].Score;
			}

			DrawText(playerName.c_str(), _Game.Options.ScreenWidth / 2.f - 160, 220 + (i * 40), 40, Theme::ForeColor);
			DrawText(score.c_str(), _Game.Options.ScreenWidth / 2.f + 140, 220 + (i * 40), 40, Theme::ForeColor);
		}

		DrawText("Press ESC to back", _Game.Options.ScreenWidth / 2.f - 200, 700, 40, Theme::ForeColor);
	}
}
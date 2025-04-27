#include "ScoreManager.h"
namespace SnakeRay
{
	ScoreManager::ScoreManager() {}
	ScoreManager::~ScoreManager() {}

	Scoreboard ScoreManager::GetScoreboardFromFile()
	{
		return Scoreboard();
	}

	Scoreboard ScoreManager::GetScoreboard()
	{
		if (_scoreBoard.size() == 0)
			_scoreBoard = GetScoreboardFromFile();

		return _scoreBoard;
	}

	bool ScoreManager::SaveScoreToFile(Player player, int difficultyLevel)
	{
		return true;
	}
}
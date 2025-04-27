#include "ScoreManager.h"

#include <algorithm>
#include <iostream>
#include <fstream>

namespace SnakeRay
{
	ScoreManager::ScoreManager() {}
	ScoreManager::~ScoreManager() {}

	Scoreboard ScoreManager::GetScoreboardFromFile()
	{
		std::ifstream scoreFile(_filePath);
		_scoreBoard = {};

		for (std::string line; std::getline(scoreFile, line);)
		{
			auto tokens = Split(line);
			_scoreBoard[std::stoi(tokens[0])].emplace_back(Player{ tokens[1], std::stoi(tokens[2]) });
		}


		scoreFile.close();

		return _scoreBoard;
	}

	Scoreboard ScoreManager::GetScoreboard(bool readFile)
	{
		if (readFile) 
			_scoreBoard = GetScoreboardFromFile();

		for (size_t i = 0; i < _scoreBoard.size(); i++)
		{
			std::sort(_scoreBoard[i].begin(), _scoreBoard[i].end());
		}

		return _scoreBoard;
	}

	bool ScoreManager::SaveScoreToFile(Player player, int difficultyLevel)
	{
		_scoreBoard[difficultyLevel].emplace_back(player);
		std::sort(_scoreBoard[difficultyLevel].begin(), _scoreBoard[difficultyLevel].end());

		if (_scoreBoard[difficultyLevel].size() > 10)
			_scoreBoard[difficultyLevel].resize(10);

		std::ofstream scoreFile;
		scoreFile.open(_filePath,  std::ios::in | std::ios::trunc);

		if (scoreFile.is_open())
		{
			for (size_t i = 0; i < 3; i++)
			{
				for (auto& scores : _scoreBoard[i])
				{
					scoreFile << std::to_string(i) + ";" + scores.Name + ";" + std::to_string(scores.Score) << "\n";
				}
			}

			scoreFile.close();
		}

		return true;
	}

	std::vector<std::string> ScoreManager::Split(const std::string& str)
	{
		std::vector<std::string> tokens;
		size_t start = 0;
		size_t end = str.find(';');

		while (end != std::string::npos)
		{
			tokens.emplace_back(str.substr(start, end - start));
			start = end + 1;
			end = str.find(';', start);
		}

		tokens.emplace_back(str.substr(start));
		return tokens;
	}
}
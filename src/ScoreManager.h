#pragma once
#include <string>
#include <array>
#include <vector>

#include "Globals.h"

namespace SnakeRay
{
	using namespace SnakeRay::Types;
	
	class ScoreManager
	{
	public:

		inline int GetScore() { return _score; }
		inline void AddScore() { _score++; }
		inline void ResetScore() { _score = 0; }

		Scoreboard GetScoreboard();

		bool IsGameReseted = false;
	private:
		ScoreManager();
		~ScoreManager();


		Scoreboard GetScoreboardFromFile();
		bool SaveScoreToFile(Player player, int difficultyLevel);
		
		friend class Game;

	private:
		int _score = 0;

		const std::string _filePath = "./score.txt";

		static inline Scoreboard _scoreBoard;


	};
}
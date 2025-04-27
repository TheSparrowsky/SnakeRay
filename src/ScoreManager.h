#pragma once
#include <string>
#include <array>

namespace SnakeRay
{
	class ScoreManager
	{
	public:
		inline int GetScore() { return _score; }
		inline void AddScore() { _score++; }
		inline void ResetScore() { _score = 0; }


		bool IsGameReseted = false;
	private:
		ScoreManager();
		~ScoreManager();

		std::array<std::string, 10> GetScoreboardFromFile();
		bool SaveScoreToFile(const char* name);
		
		friend class Game;

	private:
		int _score = 0;

		const std::string _filePath = "./score.txt";


	};
}
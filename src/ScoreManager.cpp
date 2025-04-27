#include "ScoreManager.h"
namespace SnakeRay
{
	ScoreManager::ScoreManager() {}
	ScoreManager::~ScoreManager() {}

	std::array<std::string, 10> ScoreManager::GetScoreboardFromFile()
	{
		return std::array<std::string, 10>();
	}

	bool ScoreManager::SaveScoreToFile(const char* name)
	{
		return true;
	}
}
#pragma once
#include <vector>
#include <array>
#include <string>

namespace SnakeRay
{
	namespace Types
	{
		struct Player
		{
			std::string Name;
			int Score;
		};

		using PlayerList = std::vector<Player>; 
		using Scoreboard = std::array<PlayerList, 3>; // 3 difficulty levels
	}
}
#pragma once
#include <vector>
#include <array>
#include <string>
#include "raylib.h"

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

	namespace Theme
	{
		inline Color BackgroundColor = Color{ 161,221,112,255 };
		inline Color ForeColor = Color{ 246,238,201,255 };
		inline Color SnakeColor = Color{ 121,147,81,255 };
		inline Color FoodColor = Color{ 238,78,78,255 };
	}
}
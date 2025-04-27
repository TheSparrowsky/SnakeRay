#pragma once
#include "GameScene.h"
#include "Game.h"

namespace SnakeRay
{
	class GameOverMenu : public GameScene
	{
	public:
		GameOverMenu(Game& game);

		bool OnLoad() override;
		void Update(float deltaTime) override;
		void Draw() override;

	private:
		int _scores = 0;
		const int _maxChars = 5;
		const char* _infoText = "Write your name (max 5 chars):";
		std::string _name{};

		Rectangle _textBox{};
		int _frameCounter = 0;
	};
}
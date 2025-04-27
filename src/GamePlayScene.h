#pragma once
#include "GameScene.h"

#include "Game.h" // temporary

#include "Snake.h" // temporary ?
#include "Food.h" // temporary ?
#include "PlaygroundFrame.h" // temporary ?

#include "Menu/MainMenu.h" // temporary
#include "Menu/GameOverMenu.h"

namespace SnakeRay
{
	class Snake;
	class GamePlayScene : public GameScene
	{
	public:
		GamePlayScene(SnakeRay::Game& game);
		~GamePlayScene() override;

		virtual bool OnLoad() override;

		virtual void Update(float deltaTime) override;
		virtual void Draw() override;

	private:
		void StateReset();

		Sound _backgroundMusic{};
		Sound _scoreSound{};
		Sound _deathSound{};

		std::shared_ptr<Snake> _snake = nullptr; // temporary
		std::shared_ptr<Food> _food = nullptr; // temporary
		std::shared_ptr<PlaygroundFrame> _playgroundFrame = nullptr; // temporary

		int _score = 0;

		bool _isGameOver = false;
	};
}
#pragma once
#include "GameScene.h"

#include "Game.h" // temporary

#include "Snake.h" // temporary ?
#include "Food.h" // temporary ?
#include "PlaygroundFrame.h" // temporary ?

namespace SnakeRay
{
	class GamePlayScene : public GameScene
	{
	public:
		GamePlayScene(const GameOptions& options);
		~GamePlayScene() override;

		virtual void Update(float deltaTime) override;
		virtual void Draw() override;

	private:
		const GameOptions& _options;

		Sound _backgroundMusic;
		Sound _scoreSound;
		Sound _deathSound;

		std::shared_ptr<Snake> _snake; // temporary
		std::shared_ptr<Food> _food; // temporary
		std::shared_ptr<PlaygroundFrame> _playgroundFrame; // temporary

		int _score = 0;
	};
}
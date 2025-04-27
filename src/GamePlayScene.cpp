#include "GamePlayScene.h"


namespace SnakeRay
{
	GamePlayScene::GamePlayScene(SnakeRay::Game& game) 
		: GameScene(game)
	{
	}

	GamePlayScene::~GamePlayScene()
	{
		UnloadSound(_scoreSound);
		UnloadSound(_deathSound);
		UnloadSound(_backgroundMusic);
		ObjectList.clear();
	}


	bool GamePlayScene::OnLoad()
	{
		_Game._ScoreManager.ResetScore();
		switch (_Game.CurrentDifficulty) 
		{
		case Game::EASY:
			_Game.Options.FrameOffset = 64;
			_Game.Options.PlaygroundSize = _Game.Options.CellSize * 40;
			break;
		case Game::MEDIUM:
			_Game.Options.FrameOffset = 128;
			_Game.Options.PlaygroundSize = _Game.Options.CellSize * 32;
			break;
		case Game::HARD:
			_Game.Options.FrameOffset = 192;
			_Game.Options.PlaygroundSize = _Game.Options.CellSize * 24;
		}

		_scoreSound = LoadSound("assets/sfx/click_04.wav");
		_deathSound = LoadSound("assets/sfx/down_02.wav");
		_backgroundMusic = LoadSound("assets/Music_Loop_5_Melody.wav");

		_snake = std::make_shared<Snake>(_Game); // temporary
		_food = std::make_shared<Food>(_Game); // temporary
		_playgroundFrame = std::make_shared<PlaygroundFrame>(PlaygroundProperty
			{ 
				_Game.Options.FrameOffset, 
				_Game.Options.FrameOffset, 
				(float)_Game.Options.PlaygroundSize,
				(float)_Game.Options.PlaygroundSize,
				5 
			}, _Game.Options.CellSize); 

		AddObject(_snake);
		AddObject(_food);
		AddObject(_playgroundFrame);

		return true;
	}

	void GamePlayScene::Update(float deltaTime)
	{
		if (IsKeyPressed(KEY_ESCAPE))
		{
			_Game.ChangeScene<MainMenu>();
			return;
		}

		if (_isGameOver)
		{
			_Game.ChangeScene<GameOverMenu>();
			return;
		}

		if (!IsSoundPlaying(_backgroundMusic))
		{
			PlaySound(_backgroundMusic);
		}

		if (_snake->IsCollidingWithFood(*_food)) // temporary collision detection
		{
			PlaySound(_scoreSound);
			_food->Reset();
			_snake->Grow();
			_Game._ScoreManager.AddScore();
		}

		if (_snake->IsCollidingWithFrame(*_playgroundFrame) || _snake->IsCollidingWithItself())
		{
			PlaySound(_deathSound);
			StateReset();
		}


		for (size_t i = 0; i < ObjectList.size(); i++)
		{
			ObjectList[i]->Update(deltaTime);
		}
	}

	void GamePlayScene::Draw() 
	{
		ClearBackground(Theme::BackgroundColor);

		for (size_t i = 0; i < ObjectList.size(); i++)
		{
			ObjectList[i]->Draw();
		}

		// TODO: magic numbers problem
		// TODO: should be in scene
		DrawText(("Score: " + std::to_string(_Game._ScoreManager.GetScore())).c_str(), _Game.Options.FrameOffset, _Game.Options.FrameOffset - 50, 40, Theme::ForeColor);

		std::string difficultyText = "";
		int difficultyTextOffset = 100;
		switch (_Game.CurrentDifficulty)
		{
		case Game::EASY:
			difficultyText = "Easy";
			break;
		case Game::MEDIUM:
			difficultyText = "Medium";
			difficultyTextOffset = 140;
			break;
		case Game::HARD:
			difficultyText = "Hard";
			break;
		}

		DrawText(difficultyText.c_str(), _Game.Options.FrameOffset + _Game.Options.PlaygroundSize + 10 - difficultyTextOffset, _Game.Options.FrameOffset - 50, 40, Theme::ForeColor);
		DrawText("SnakeRay", _Game.Options.ScreenWidth / 2.f - 100, _Game.Options.PlaygroundSize + _Game.Options.FrameOffset + 10, 40, Theme::ForeColor);
	}

	void GamePlayScene::StateReset()
	{
		_snake->Reset();
		_food->Reset();

		_isGameOver = true;
	}
}
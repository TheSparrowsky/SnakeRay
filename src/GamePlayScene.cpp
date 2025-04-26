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
		_scoreSound = LoadSound("assets/sfx/click_04.wav");
		_deathSound = LoadSound("assets/sfx/down_02.wav");
		_backgroundMusic = LoadSound("assets/Music_Loop_5_Melody.wav");

		_snake = std::make_shared<Snake>(_Game.Options.CellSize); // temporary
		_food = std::make_shared<Food>(_Game.Options.CellSize); // temporary
		_playgroundFrame = std::make_shared<PlaygroundFrame>(PlaygroundProperty{ _Game.Options.FrameOffset, _Game.Options.FrameOffset, (float)_Game.Options.ScreenWidth, (float)_Game.Options.ScreenHeight, 5 }, _Game.Options.CellSize); // temporary

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

		if (!IsSoundPlaying(_backgroundMusic))
		{
			PlaySound(_backgroundMusic);
		}

		if (_snake->IsCollidingWithFood(*_food)) // temporary collision detection
		{
			PlaySound(_scoreSound);
			_food->Reset();
			_snake->Grow();
			_score++;
		}

		if (_snake->IsCollidingWithFrame(*_playgroundFrame))
		{
			PlaySound(_deathSound);
			_snake->Reset();
			_food->Reset();
			_score = 0;
		}


		for (size_t i = 0; i < ObjectList.size(); i++)
		{
			ObjectList[i]->Update(deltaTime);
		}
	}

	void GamePlayScene::Draw() 
	{
		int realWindowWidth = _Game.Options.ScreenWidth + (2 * _Game.Options.FrameOffset);
		int realWindowHeight = _Game.Options.ScreenHeight + (2 * _Game.Options.FrameOffset);

		ClearBackground(Color{ 161,221,112,255 });

		for (size_t i = 0; i < ObjectList.size(); i++)
		{
			ObjectList[i]->Draw();
		}

		// TODO: magic numbers problem
		// TODO: should be in scene
		DrawText(("Score: " + std::to_string(_score)).c_str(), _Game.Options.FrameOffset, _Game.Options.FrameOffset - 50, 40, Color{ 246,238,201,255 });
		DrawText("SnakeRay", realWindowWidth / 2 - (30 * 4), _Game.Options.ScreenHeight + _Game.Options.FrameOffset + 10, 40, Color{ 246,238,201,255 });

	}
}
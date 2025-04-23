#include "MainMenuScene.h"

namespace SnakeRay
{
	MainMenuScene::MainMenuScene(SnakeRay::Game* game)
		: GameScene(game), _gameOptions(&game->Options)
	{
		_currentSelected = &_menuOptions[MenuItems::PLAY];
	}

	MainMenuScene::~MainMenuScene()
	{
		_gameOptions = nullptr;
		_currentSelected = nullptr;
	}

	void MainMenuScene::Update(float deltaTime)
	{
		if (IsKeyPressed(KEY_W))
			_currentSelectedIndex--;
		else if (IsKeyPressed(KEY_S))
			_currentSelectedIndex++;
		
		auto castedItem = static_cast<MenuItems>(_currentSelectedIndex);
		_currentSelected = &_menuOptions[castedItem];
		
		if (IsKeyPressed(KEY_ENTER))
		{
			switch (castedItem)
			{
				case MenuItems::PLAY:
					GamePtr->ChangeScene(GamePtr->GameSceneManager.CreateScene<GamePlayScene>(GamePtr));
					break;
				case MenuItems::SCOREBOARD:
					break;
				case MenuItems::OPTIONS:
					break;
				case MenuItems::EXIT:
					GamePtr->Exit();
					break;
				default:
					break;
			}
			return;
		}


		if (_currentSelectedIndex < MenuItems::PLAY)
			_currentSelectedIndex = MenuItems::EXIT;
		else if (_currentSelectedIndex > MenuItems::EXIT)
			_currentSelectedIndex = MenuItems::PLAY;

	}

	void MainMenuScene::Draw()
	{
		ClearBackground(Color{ 161,221,112,255 }); // same in GamePlayScene

		DrawText("SnakeRay", _gameOptions->ScreenWidth / 2, 64, 40, Color{ 246,238,201,255 });

		for (auto& menuOption : _menuOptions)
		{
			DrawText(menuOption.second.Name.c_str(), menuOption.second.Position.x, menuOption.second.Position.y, 40, Color{ 246,238,201,255 });
		}

		DrawText(">", _currentSelected->Position.x - _selectorOffsetX, _currentSelected->Position.y, 40, Color{ 246,238,201,255 });
	}
}
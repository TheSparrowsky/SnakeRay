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
		else if (IsKeyPressed(KEY_ENTER))
		{
			// TODO: gamescene manager? 
			// TODO: which menu option is selected?
			GamePtr->ChangeScene(std::make_unique<GamePlayScene>(GamePtr));
			return;
		}


		if (_currentSelectedIndex < MenuItems::PLAY)
			_currentSelectedIndex = MenuItems::EXIT;
		else if (_currentSelectedIndex > MenuItems::EXIT)
			_currentSelectedIndex = MenuItems::PLAY;

		_currentSelected = &_menuOptions[static_cast<MenuItems>(_currentSelectedIndex)];
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
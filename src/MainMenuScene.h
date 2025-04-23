#pragma once
#include "GameScene.h"
#include "Game.h" // temp

#include <unordered_map>
#include <memory>
#include "GamePlayScene.h"

namespace SnakeRay
{
	class MainMenuScene : public GameScene
	{
	public:
		MainMenuScene(SnakeRay::Game* game);
		~MainMenuScene();

		virtual bool OnLoad() override { return true; };

		void Update(float deltaTime) override;
		void Draw() override;

	private:
		enum MenuItems
		{
			PLAY = 0,
			SCOREBOARD,
			OPTIONS,
			EXIT
		};

		struct MenuOption
		{
			std::string Name;
			Vector2 Position;
		};

		float _selectorOffsetX = 40;
		GameOptions* _gameOptions = nullptr;
		MenuOption* _currentSelected = nullptr;
		int _currentSelectedIndex = 0;

		// TODO: position y couple with font size
		std::unordered_map<MenuItems, MenuOption> _menuOptions = {
			{ MenuItems::PLAY, MenuOption{"Play", {(float)_gameOptions->ScreenWidth / 2, 128}}},
			{ MenuItems::SCOREBOARD, MenuOption{"Scoreboard", {(float)_gameOptions->ScreenWidth / 2, 168}}},
			{ MenuItems::OPTIONS, MenuOption{"Options", {(float)_gameOptions->ScreenWidth / 2, 208}}},
			{ MenuItems::EXIT, MenuOption{"Exit", {(float)_gameOptions->ScreenWidth / 2, 248}}}
		};





	};
}
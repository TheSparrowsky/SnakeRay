#pragma once
#include <vector>
#include <memory>
#include "GameObject.h"

namespace SnakeRay
{
	class Game;
	class GameScene
	{
	public:
		using GameObjects = std::vector<std::shared_ptr<GameObject>>;

		GameScene(Game* game) : GamePtr(game), ObjectList(std::vector<std::shared_ptr<GameObject>>()) {}
		virtual ~GameScene() {};

		virtual bool OnLoad() = 0;

		virtual void Update(float deltaTime) = 0;
		virtual void Draw() = 0;

	protected:
		Game* GamePtr = nullptr;
		void AddObject(std::shared_ptr<GameObject> gameObject) { ObjectList.push_back(gameObject); }

		GameObjects ObjectList;
	};
}
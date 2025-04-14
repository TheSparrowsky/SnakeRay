#pragma once
#include <vector>
#include <memory>
#include "GameObject.h"

namespace SnakeRay
{
	class GameScene
	{
	public:
		using GameObjects = std::vector<std::shared_ptr<GameObject>>;

		GameScene() : ObjectList(std::vector<std::shared_ptr<GameObject>>()) {}
		virtual ~GameScene() {};

		virtual void Update(float deltaTime) = 0;
		virtual void Draw() = 0;

	protected:
		void AddObject(std::shared_ptr<GameObject> gameObject) { ObjectList.push_back(gameObject); }

		GameObjects ObjectList;
	};
}
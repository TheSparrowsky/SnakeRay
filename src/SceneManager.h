#pragma once
#include <memory>

namespace SnakeRay
{
	class Game;
	class SceneManager
	{
	public:
		template<typename T>
		std::shared_ptr<T> CreateScene(Game* game)
		{
			auto scene = std::make_shared<T>(game);
			if (scene->OnLoad())
			{
				return scene;
			}

			return nullptr;
		}
	};
}
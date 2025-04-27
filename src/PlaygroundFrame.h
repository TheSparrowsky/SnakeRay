#pragma once
#include "GameObject.h"
#include "raylib.h"

#include "Globals.h"

namespace SnakeRay
{
	struct PlaygroundProperty
	{
		float x;
		float y;
		float width;
		float height;
		int lineThick;
	};

	class PlaygroundFrame : public GameObject
	{
	public:
		PlaygroundFrame(const PlaygroundProperty& properties, int cellSize);

		virtual void Update(float deltaTime) override {};
		virtual void Draw() override;

		float GetWidth() const { return _rectangle.width - (2 * _lineThick); }
		float GetHeight() const { return _rectangle.height - (2 * _lineThick); }

	private:
		float _lineThick;
		Rectangle _rectangle;
	};
}
#pragma once
#include "GameObject.h"
#include "raylib.h"

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

		Color _frameColor{246,238,201,255};
		Rectangle _rectangle;
	};
}
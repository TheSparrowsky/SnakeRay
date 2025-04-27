#include "PlaygroundFrame.h"

namespace SnakeRay
{
	PlaygroundFrame::PlaygroundFrame(const PlaygroundProperty& properties, int cellSize)
		: GameObject(cellSize)
	{
		Position = Vector2{ properties.x - properties.lineThick,properties.y  - properties.lineThick};
		
		_lineThick = properties.lineThick;

		_rectangle = Rectangle{ Position.x, Position.y, properties.width + (2 * properties.lineThick), properties.height + (2 * properties.lineThick)};
	}


	void PlaygroundFrame::Draw()
	{
		DrawRectangleLinesEx(_rectangle, _lineThick, Theme::ForeColor);
	}
}

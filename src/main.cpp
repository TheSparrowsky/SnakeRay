#include "raylib.h"
#include "Snake.h"

int main()
{
	InitWindow(600, 600, "SnakeRay");
	SetTargetFPS(60);

	SnakeRay::Snake snake = SnakeRay::Snake{ 16 };
	while (!WindowShouldClose())
	{
		auto deltaTime = GetFrameTime();

		BeginDrawing();
		ClearBackground(Color{161,221,112,255});

		snake.Update(deltaTime);

		snake.Draw();

		EndDrawing();
	}

	CloseWindow();
}
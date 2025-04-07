#include "raylib.h"
#include "Snake.h"
#include "Food.h"

int main()
{
	InitWindow(768, 768, "SnakeRay");
	SetTargetFPS(60);

	SnakeRay::Snake snake = SnakeRay::Snake{ 16 };
	SnakeRay::Food food = SnakeRay::Food{ 16 };
	while (!WindowShouldClose())
	{
		auto deltaTime = GetFrameTime();

		BeginDrawing();
		ClearBackground(Color{161,221,112,255});

		if (snake.IsCollidingWithFood(food))
		{
			food = SnakeRay::Food{ 16 };
			snake.Grow();
		}

		snake.Update(deltaTime);
		food.Update(deltaTime);

		snake.Draw();
		food.Draw();

		EndDrawing();
	}

	CloseWindow();
}
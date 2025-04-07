#include "raylib.h"

int main()
{
	InitWindow(600, 600, "SnakeRay");
	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(WHITE);


		EndDrawing();
	}

	CloseWindow();
}
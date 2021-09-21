#include <iostream>
#include "raylib.h"



int main() {

	
	InitWindow(700, 700, "text");

	SetTargetFPS(60);


	while (!WindowShouldClose()) {


		BeginDrawing();

		ClearBackground(RAYWHITE);

		DrawText("welcome ", 300, 300, 30, SKYBLUE);

		EndDrawing();


	}

	CloseWindow();


	return 0;
}
#include <iostream>
#include "raylib.h"
#include <list>
#include "Ball.h"

// delta time = GetFrameTime();
void GetMove(float* x, float* y) {
	if (IsKeyDown(KEY_A)) 
		(*x)--;
	

	if (IsKeyDown(KEY_D)) 
		(*x)++;
	

	if (IsKeyDown(KEY_W)) 
		(*y)--;
	

	if (IsKeyDown(KEY_S)) 
		(*y)++;
	
}


int main() {

	Ball ball(Vector2{ 0,0 }, 30, RED);
	char ballText[40] = "";

	const int WindowWidht = 1200;
	const int WindowHeight = 700;

	InitWindow(WindowWidht, WindowHeight, "text");
	SetTargetFPS(60);

	float xpos = WindowWidht/2;
	float ypos = WindowHeight/2;

	Vector2 velocityVector{ 50,-20 }; // average 
	Vector2 netForceVector;
	
	std::list<Vector2> forceVectorList;



	double DeltaTime;



	while (!WindowShouldClose()) {

		DeltaTime = GetFrameTime();
		sprintf(ballText, "Ball pos: x = %d ,%d", (int)xpos, (int)ypos);

		DrawText(ballText, 10, 10, 30, BLACK);

		GetMove(&xpos, &ypos); 


		ball.SetPosition(xpos+= velocityVector.x * DeltaTime , ypos += velocityVector.y * DeltaTime);
		BeginDrawing();

		ClearBackground(DARKPURPLE);
		ball.DrawBall();

		EndDrawing();
	}

	CloseWindow();


	return 0;
}
#include <iostream>
#include <vector>

#include "raylib.h"
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

	InitWindow(WindowWidht, WindowHeight, "Game Physics");
	SetTargetFPS(60);

	float xpos = WindowWidht/2;
	float ypos = WindowHeight/2;
	Vector2 pos = {xpos,ypos};

	//delta time;
	double DeltaTime;
	Vector2 DeltaTime2{ 0,0 };


	Vector2 velocityVector{ 1,0 }; // average 

	std::vector<Vector2> netForceVector(3);
	std::vector<Vector2>::iterator netforceIterator = netForceVector.begin();

	// NET FORCE;
	netForceVector.at(0) = Vector2{ 1,1 };
	netForceVector.at(1) = Vector2{ 5,1 };
	netForceVector.at(2) = Vector2{ -6,-2 };

	Vector2 netForce{ 0,0 };

	while (!WindowShouldClose()) {

		DeltaTime = GetFrameTime();
		DeltaTime2.x = DeltaTime;
		DeltaTime2.y = DeltaTime;

		sprintf(ballText, "Ball pos: x = %d , y = %d", (int)pos.x, (int)pos.y);
		DrawText(ballText, 10, 10, 30, BLACK);

		GetMove(&pos.x, &pos.y); 
		netForce = Vector2{ 0,0 };

		while(netforceIterator != netForceVector.end()) {
			netForce = netForce + (*netforceIterator);
			netforceIterator++;
		}netforceIterator = netForceVector.begin();
		

		if (netForce.x == 0 && netForce.y == 0) {
			pos += (velocityVector) + netForce * DeltaTime2;
		}
		else {
			DrawText("UNBALANCED FORCE DECTED", 10, 39, 30, BLACK);
		}
		ball.SetPosition(pos);



		BeginDrawing();

		ClearBackground(DARKPURPLE);
		ball.DrawBall();

		EndDrawing();
	}

	CloseWindow();


	return 0;
}
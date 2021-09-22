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
	char velocityVectorChar[20] = "";
	char AcclerationChar[20] = "";


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

	std::vector<Vector2> netForceVector(3);
	std::vector<Vector2>::iterator netforceIterator = netForceVector.begin();

	Vector2 velocityVector{ 0,0 }; // average 

	// NET FORCE;
	netForceVector.at(0) = Vector2{ 4,0 };
	netForceVector.at(1) = Vector2{ 1,0 };
	netForceVector.at(2) = Vector2{ 0,2 };

	Vector2 netForce{ 0,0 };
	// mass;
	float mass = 30;
	Vector2 accelerationVector{ 0,0 };


	while (!WindowShouldClose()) {

		DeltaTime = GetFrameTime();
		DeltaTime2.x = DeltaTime;
		DeltaTime2.y = DeltaTime;


		GetMove(&pos.x, &pos.y); 
		netForce = Vector2{ 0,0 };

		while(netforceIterator != netForceVector.end()) {
			netForce = netForce + (*netforceIterator);
			netforceIterator++;
		}netforceIterator = netForceVector.begin();
		

		accelerationVector = { netForce.x / mass, netForce.y / mass };
		velocityVector += accelerationVector *DeltaTime2;
		std::cout << velocityVector.x << " << " << velocityVector.y << std::endl;

		// update positoin;
		pos += (velocityVector) + netForce* DeltaTime2;
		ball.SetPosition(pos);



		// Drawing;
		BeginDrawing();

		sprintf(ballText, "Ball pos: x = %d , y = %d", (int)pos.x-600, (int)pos.y-350);
		DrawText(ballText, 10, 10, 30, BLACK);

		sprintf(velocityVectorChar, "Velocity: x = %.2f, y = %.2f", velocityVector.x, velocityVector.y);
		DrawText(velocityVectorChar, 10, 35, 30, BLACK);

		sprintf(AcclerationChar, "Accleration: x = %.2f, y = %.2f", accelerationVector.x, accelerationVector.y);
		DrawText(AcclerationChar, 10, 65, 30, BLACK);


		ClearBackground(DARKPURPLE);
		ball.DrawBall();

		EndDrawing();
	}

	CloseWindow();


	return 0;
}
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
	char massCahr[15] = "";


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
	netForceVector.at(0) = Vector2{ 0,0 };
	netForceVector.at(1) = Vector2{ 0,0 };
	netForceVector.at(2) = Vector2{ 0,1 };

	Vector2 netForce{ 0,0 };
	// mass;
	float mass = 50;
	Vector2 accelerationVector{ 0,0 };


	// CAMERA SETUP
	Camera2D camera = { 0 };
	camera.target = Vector2{ ball.m_Position.x, ball.m_Position.y };
	camera.offset = Vector2{ WindowWidht / 2.0f, WindowHeight / 2.0f };
	camera.rotation = 0.0f;
	camera.zoom = 1.0f;



	while (!WindowShouldClose()) {
		// camera Controls;
  // Camera target follows player
		camera.target = Vector2{ ball.m_Position.x, ball.m_Position.y };

		// Camera zoom controls
		camera.zoom += ((float)GetMouseWheelMove() * 0.05f);

		if (camera.zoom > 3.0f) camera.zoom = 3.0f;
		else if (camera.zoom < 0.1f) camera.zoom = 0.1f;

		// Camera reset (zoom and rotation)
		if (IsKeyPressed(KEY_R))
		{
			camera.zoom = 1.0f;
			camera.rotation = 0.0f;
		}


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

		// update positoin;
		pos += (velocityVector)+netForce * DeltaTime2;
		ball.SetPosition(pos);

		// Drawing;
		BeginDrawing();
		ClearBackground(DARKPURPLE);

		BeginMode2D(camera); //  inCamera Control;
		
		ball.DrawBall();
		
		EndMode2D();

		sprintf(ballText, "Ball pos: x = %d , y = %d", (int)pos.x-600, (int)pos.y-350); // -offset;
		DrawText(ballText, 10, 10, 20, WHITE);

		sprintf(velocityVectorChar, "Velocity: x = %.2f, y = %.2f", velocityVector.x, velocityVector.y);
		DrawText(velocityVectorChar, 10, 30, 20, WHITE);

		sprintf(AcclerationChar, "Accleration: x = %.2f, y = %.2f", accelerationVector.x, accelerationVector.y);
		DrawText(AcclerationChar, 10, 50, 20, WHITE);

		sprintf(massCahr, "Mass= %.1f kg",mass);
		DrawText(massCahr, 10, 70, 20, WHITE);



		EndDrawing();
	}

	CloseWindow();


	return 0;
}
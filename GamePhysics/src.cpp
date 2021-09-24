#include <iostream>
#include <vector>

#include "raylib.h"
#include "Ball.h"

#include "GUIText.h"


// delta time = GetFrameTime();


int main() {

	// gui text;
	GUIText TextBallPos(850, 10, 20, Color(WHITE), true);
	GUIText TextvelocityVector(850, 30, 20, Color(WHITE), true);
	GUIText TextAccleration(850, 50, 20, Color(WHITE), true);
	GUIText TextMass(850, 70, 20, Color(WHITE), true);


	// object;
	Ball ball(Vector2{ 0,0 }, 30, RED);


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
	netForceVector.at(1) = Vector2{ 1,0 };
	netForceVector.at(2) = Vector2{ 0,0 };
	Vector2 netForce{ 0,0 };

	// mass;
	float mass = 20;
	Vector2 accelerationVector{ 0,0 };



	Vector2 mousePoint = { 0.0f, 0.0f };
	Texture2D add = LoadTexture("res\\add.png");
	Texture2D sub = LoadTexture("res\\sub.png");

	Rectangle addSrceRec = { 0,0, 25, 25};
	Rectangle addbtnBounds = { 0,0,25,25 };


	// CAMERA SETUP
	Camera2D camera = { 0 };
	camera.target = Vector2{ ball.m_Position.x, ball.m_Position.y };
	camera.offset = Vector2{ WindowWidht / 2.0f, WindowHeight / 2.0f };
	camera.rotation = 0.0f;
	camera.zoom = 1.0f;



	while (!WindowShouldClose()) {

		if (CheckCollisionPointRec(mousePoint, addbtnBounds)) {
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
				velocityVector.x++;
			
		}



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

		// mouse pos:
		mousePoint = GetMousePosition();

		DeltaTime = GetFrameTime();
		DeltaTime2.x = (float)DeltaTime;
		DeltaTime2.y = (float)DeltaTime;


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


		DrawTextureRec(add, addSrceRec, Vector2{ 2,3 }, WHITE);

		TextBallPos.UpdateText("Ball pos: x = %d , y = %d", (int)pos.x - 600, (int)pos.y - 350);
		TextvelocityVector.UpdateText("Velocity: x = %.2f, y = %.2f", velocityVector.x, velocityVector.y);
		TextAccleration.UpdateText("Accleration: x = %.2f, y = %.2f", accelerationVector.x, accelerationVector.y);
		TextMass.UpdateText("Mass= %.1f kg", mass);

		EndDrawing();
	}
	CloseWindow();


	return 0;
}
#include <iostream>
#include <vector>

#include "raylib.h"
#include "Ball.h"

#include "GUIText.h"

// gui text;

int main() {
	//right side
	GUIText TextBallPos(850, 10, 20, Color(WHITE), true);
	GUIText TextvelocityVector(850, 30, 20, Color(WHITE), true);
	GUIText TextAccleration(850, 50, 20, Color(WHITE), true);
	GUIText TextMass(850, 70, 20, Color(WHITE), true);
	// left side;
	GUIText TextnetForceVector1(80, 0, 20, Color(WHITE), true);

	
	// object;
	Ball ball(Vector2{ 0,0 }, 30, RED);
	Ball ball1(Vector2{ 10,10}, 30, BLUE);


	const int WindowWidht = 1200;
	const int WindowHeight = 700;

	InitWindow(WindowWidht, WindowHeight, "Game Physics");
	SetTargetFPS(60);


	float xpos = WindowWidht/2;
	float ypos = WindowHeight/2;

	Vector2 pos = {xpos,ypos};
	Vector2 pos1 = { xpos, ypos + 150 };

	//delta time;
	double DeltaTime;
	Vector2 DeltaTime2{ 0,0 };

	//gravity; --(bool)--

	std::vector<Vector2> netForceVectorList(3);
	std::vector<Vector2>::iterator netforceIterator = netForceVectorList.begin();

	Vector2 velocityVector{ 0,0 }; // average 

	// NET FORCE;
	netForceVectorList.at(0) = Vector2{ 0,0 };
	netForceVectorList.at(1) = Vector2{ 0,0 };
	netForceVectorList.at(2) = Vector2{ 0,0 };
	Vector2 netForce{ 0,0 };

	// mass;
	float mass = 1;
	Vector2 accelerationVector{ 0,0 };

	Vector2 mousePoint = { 0.0f, 0.0f };

	Texture2D add = LoadTexture("res\\add.png");
	Texture2D sub = LoadTexture("res\\sub.png");

	Rectangle addSrceRec = { 0,0, 25, 25};
	Rectangle addbtnBounds = { 0,0,25, 25};

	Rectangle _addSrceRec = { 0,0, 25, 25 };
	Rectangle _addbtnBounds = { 50,0,75,25 };



	// CAMERA SETUP
	Camera2D camera = { 0 };
	camera.target = Vector2{ ball.m_Position.x, ball.m_Position.y };
	camera.offset = Vector2{ WindowWidht / 2.0f, WindowHeight / 2.0f };
	camera.rotation = 0.0f;
	camera.zoom = 1.0f;



	while (!WindowShouldClose()) {
	
		// netfor 1;
		if (CheckCollisionPointRec(mousePoint, addbtnBounds)) {
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			{
				//velocityVector.x++;
				netForceVectorList.at(0).x++;
			}

			if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON)) 
			{

				//velocityVector.x--;
				netForceVectorList.at(0).x--;
			}
		}

		if (CheckCollisionPointRec(mousePoint, _addbtnBounds)) {
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			{

				//velocityVector.y++;
				netForceVectorList.at(0).y++ * -1;
			}

			if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON))
			{

				//velocityVector.y--;
				netForceVectorList.at(0).y-- * -1;
			}
		}
		
		//netfor 2;


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

		while(netforceIterator != netForceVectorList.end()) {
			netForce = netForce + (*netforceIterator);
			netforceIterator++;
		}netforceIterator = netForceVectorList.begin();
		


		accelerationVector = { netForce.x / mass, netForce.y / mass };
		velocityVector += accelerationVector *DeltaTime2;

		// update positoin;
		pos += (velocityVector)+netForce * DeltaTime2;
		ball.SetPosition(pos);

		pos1 += (velocityVector)+netForce * DeltaTime2;
		ball1.SetPosition(pos1);


		// Drawing;
		BeginDrawing();
		ClearBackground(BLACK);

		BeginMode2D(camera); //  inCamera Control;

		// DRAWING CHECKS
		for (int i = 1; i < 100; i++) {
			DrawLine(10 * i * (10), 10, 10 * i * (10), 5000, GREEN);
			DrawLine(10, 10*i*(10), 5000, 10*i*(10), GREEN);
		}

		ball.DrawBall();
		ball1.DrawBall();


		EndMode2D();


		DrawTextureRec(add, addSrceRec, Vector2{ 0,0 }, WHITE);
		DrawTextureRec(add, _addSrceRec, Vector2{ 50,0 }, WHITE);

		TextBallPos.UpdateText("Ball pos: x = %d , y = %d", (int)pos.x - 600, (int)pos.y - 350);
		TextvelocityVector.UpdateText("Velocity: x = %.2f, y = %.2f", velocityVector.x, velocityVector.y);
		TextAccleration.UpdateText("Accleration: x = %.2f, y = %.2f", accelerationVector.x, accelerationVector.y);
		TextMass.UpdateText("Mass= %.1f kg", mass);

		TextnetForceVector1.UpdateText("Force 1: x = %.2f, y = %.2f", netForceVectorList.at(0).x, netForceVectorList.at(0).y);


		EndDrawing();
	}
	CloseWindow();


	return 0;
}
#pragma once
#include <raylib.h>


class Ball
{
private:
	Vector2 m_Position;
	float m_Radius;
	Color m_Color;

public:

	Ball(Vector2 position, float radius, Color color);

	void SetPosition(float x, float y);


	// drawing;
	void DrawBall()const;
};


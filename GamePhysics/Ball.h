#pragma once
#include <raylib.h>

class Ball
{
public:
	Vector2 m_Position;
private:

	float m_Radius;
	Color m_Color;

public:

	Ball(Vector2 position, float radius, Color color);

	void SetPosition(Vector2 source);

	// drawing;
	void DrawBall()const;
};


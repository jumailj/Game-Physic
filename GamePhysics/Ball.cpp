#include "Ball.h"



Ball::Ball(Vector2 position, float radius, Color color)
	:m_Position{ position }, m_Radius{ radius }, m_Color{ color }
{

}

void Ball::SetPosition(float x, float y)
{
	m_Position.x = x;
	m_Position.y = y;
}

void Ball::DrawBall()const {
	DrawCircle(m_Position.x, m_Position.y, m_Radius, m_Color);
}
#include "Ball.h"

Ball::Ball(Vector2 position, float radius, Color color)
	:m_Position{ position }, m_Radius{ radius }, m_Color{ color }
{

}

void Ball::SetPosition(Vector2 source)
{
	m_Position.x = source.x;
	m_Position.y = source.y;
}

void Ball::DrawBall()const {
	DrawCircle(m_Position.x, m_Position.y, m_Radius, m_Color);
	//DrawRectangle(m_Position.x, m_Position.y, 30, 2, WHITE);
}
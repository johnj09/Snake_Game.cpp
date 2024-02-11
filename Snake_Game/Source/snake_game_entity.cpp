#include "snake_game_food.h"
#include "snake_game_snake.h"
#include <iostream>

#pragma region CFood
CFood::CFood() {}

Vector2 CFood::get_position() const
{
	return m_vfPos;
}

GAME_FLOAT CFood::get_position_x() const
{
	return m_vfPos.x;
}

GAME_FLOAT CFood::get_position_y() const
{
	return m_vfPos.y;
}

Image CFood::get_image() const
{
	return m_Image;
}

void CFood::set_position(const Vector2 &vPos)
{
	m_vfPos = vPos;
}
#pragma endregion

#pragma region CSnake
CSnake::CSnake()
{
	dqvSnakeBody.push_back({ GAME_CELL_COUNT / 2, GAME_CELL_COUNT / 2 });
	m_u32Size = 1;
}

CSnake::~CSnake()
{

}

GAME_U32 CSnake::get_size() const
{
	return m_u32Size;
}

std::deque<Vector2> CSnake::get_snake_body() const
{
	return dqvSnakeBody;
}

void CSnake::update_snake_direction(SNAKE_DIRECTION enDirection)
{
	if (m_enDirection == SNAKE_DIRECTION_UP && enDirection != SNAKE_DIRECTION_DOWN)
	{
		m_enDirection = enDirection;
	}
	else if (m_enDirection == SNAKE_DIRECTION_DOWN && enDirection != SNAKE_DIRECTION_UP)
	{
		m_enDirection = enDirection;
	}
	else if (m_enDirection == SNAKE_DIRECTION_LEFT && enDirection != SNAKE_DIRECTION_RIGHT)
	{
		m_enDirection = enDirection;
	}
	else if (m_enDirection == SNAKE_DIRECTION_RIGHT && enDirection != SNAKE_DIRECTION_LEFT)
	{
		m_enDirection = enDirection;
	}

	switch (m_enDirection)
	{
	case SNAKE_DIRECTION_UP:
		m_vMovement = SNAKE_MOVEMENT_UP;
		break;
	case SNAKE_DIRECTION_DOWN:
		m_vMovement = SNAKE_MOVEMENT_DOWN;
		break;
	case SNAKE_DIRECTION_LEFT:
		m_vMovement = SNAKE_MOVEMENT_LEFT;
		break;
	case SNAKE_DIRECTION_RIGHT:
		m_vMovement = SNAKE_MOVEMENT_RIGHT;
		break;
	default:
		break;
	}
}

void CSnake::update_snake_body()
{
	dqvSnakeBody.push_front(Vector2Add(dqvSnakeBody[0], m_vMovement));
	if (m_bSizeUp == false)
	{
		dqvSnakeBody.pop_back();
	}
	m_bSizeUp = false;
}

void CSnake::increase_snake_size()
{
	m_bSizeUp = true;
	m_u32Size++;
}
#pragma endregion


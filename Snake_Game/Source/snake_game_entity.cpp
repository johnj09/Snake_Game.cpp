#include "snake_game_food.h"
#include "snake_game_snake.h"
#include <iostream>

#pragma region CFood
CFood::CFood() {}

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

void CFood::initialize_position()
{
	m_vfPos = generate_random_pos();
}

Vector2 CFood::generate_random_pos()
{
	GAME_FLOAT fPosX = static_cast<GAME_FLOAT>(GetRandomValue(0, GAME_CELL_COUNT - 1));
	GAME_FLOAT fPosY = static_cast<GAME_FLOAT>(GetRandomValue(0, GAME_CELL_COUNT - 1));
	std::cout << fPosX << " " << fPosY << std::endl;


	return Vector2{ fPosX, fPosY };
}
#pragma endregion

#pragma region CSnake
CSnake::CSnake()
{
	dqvSnakeBody.push_back({ 20, 20 });
	dqvSnakeBody.push_back({ 21, 20 });
	dqvSnakeBody.push_back({ 22, 20 });
	m_u32Size = 3;
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


	dqvSnakeBody.pop_back();
	dqvSnakeBody.push_front(Vector2Add(dqvSnakeBody[0], m_vMovement));
}
#pragma endregion


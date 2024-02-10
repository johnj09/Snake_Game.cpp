#ifndef __SNAKE_GAME_SNAKE_H__
#define __SNAKE_GAME_SNAKE_H__

#include "snake_game_macro.h"
#include "raylib.h"
#include "raymath.h"
#include <vector>
#include <deque>

#define SNAKE_MOVEMENT_UP		{ 0, -1 }
#define SNAKE_MOVEMENT_DOWN	{ 0, 1 }
#define SNAKE_MOVEMENT_LEFT	{ -1, 0 }
#define SNAKE_MOVEMENT_RIGHT	{ 1, 0 }

typedef enum SNAKE_DIRECTION
{
	SNAKE_DIRECTION_UP = 1,
	SNAKE_DIRECTION_DOWN = 2,
	SNAKE_DIRECTION_LEFT = 3,
	SNAKE_DIRECTION_RIGHT = 4,
	SNAKE_DIRECTION_MAX
} SNAKE_DIRECTION;

struct SNAKE_NODE
{
	SNAKE_NODE *next_node;
	Vector2 position;
	

	SNAKE_NODE(Vector2 position)
	{
		next_node = nullptr;
		this->position = position;
	}
};

class CSnake
{
public:
	CSnake();
	~CSnake();

	// Getters
	GAME_U32 get_size() const;
	std::deque<Vector2> get_snake_body() const;

	void update_snake_direction(SNAKE_DIRECTION enDirection);
	void update_snake_body();

private:
	std::deque<Vector2> dqvSnakeBody;
	GAME_U32 m_u32Size;
	SNAKE_DIRECTION m_enDirection = SNAKE_DIRECTION_LEFT;
	Vector2 m_vMovement = SNAKE_MOVEMENT_LEFT;
};

#endif // !__SNAKE_GAME_SNAKE_H__

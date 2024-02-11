#ifndef __SNAKE_GAME_FOOD_H__
#define __SNAKE_GAME_FOOD_H__

#include "snake_game_macro.h"
#include "raylib.h"

class CFood
{
public:
	CFood();

	// Getters
	Vector2 get_position() const;
	// TODO: consider removing get_position_x and get_position_y
	GAME_FLOAT get_position_x() const;
	GAME_FLOAT get_position_y() const;
	Image get_image() const;

	void set_position(const Vector2 &vPos);

private:
	const Image m_Image = LoadImage("..\\Resources\\food.png");
	Vector2 m_vfPos;
};

#endif // !__SNAKE_GAME_FOOD_H__

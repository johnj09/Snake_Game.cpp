#ifndef __SNAKE_GAME_FOOD_H__
#define __SNAKE_GAME_FOOD_H__

#include "snake_game_macro.h"
#include "raylib.h"

class CFood
{
public:
	CFood();

	// Getters
	GAME_FLOAT get_position_x() const;
	GAME_FLOAT get_position_y() const;
	Image get_image() const;

	void initialize_position();

private:
	const Image m_Image = LoadImage("..\\Resources\\food_18px.png");
	Vector2 m_vfPos;

	Vector2 generate_random_pos();
};

#endif // !__SNAKE_GAME_FOOD_H__

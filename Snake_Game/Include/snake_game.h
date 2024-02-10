#ifndef __SNAKE_GAME_H__
#define __SNAKE_GAME_H__

#include "snake_game_macro.h"
#include "snake_game_snake.h"
#include "snake_game_food.h"
#include "raylib.h"

#define GAME_UPDATE_INTERVAL 0.2

class CSnakeGame
{
public:
	CSnakeGame();
	~CSnakeGame();

	void run();

private:
	// Game Window
	const GAME_S32 m_s32WindowWidth = 800;
	const GAME_S32 m_s32WindowHeight = 800;
	const char *m_pcGameName = "Snake Game";
	const GAME_S32 m_s32TargetFPS = 165;
	
	// Colours
	const Color m_bgColour = { 204, 183, 174, 255 };
	const Color m_entityColour = { 105, 103, 115, 255 };

	// Game Logic
	const GAME_FLOAT m_fGridSize = 20;
	const GAME_S32 m_s32GridCount = GAME_CELL_COUNT;
	GAME_DOUBLE m_dLastUpdateTime = 0;
	GAME_BOOL m_bCanPressKey = true;
	SNAKE_DIRECTION m_enNextMove = SNAKE_DIRECTION_LEFT;

	// Game Entities
	CFood *m_pFood;
	CSnake *m_pSnake;

	// GUI Functions
	void initialize();
	GAME_S32 main_loop();
	void set_background_colour(const Color bgColour);
	void draw_game();
	void draw_food();
	void draw_snake();
	void read_keyboard_inputs();

	// Game Logic Functions
	GAME_BOOL update_interval_passed();
};

#endif // !__SNAKE_GAME_H__

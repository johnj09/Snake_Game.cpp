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
	const GAME_FLOAT m_fGridSize = 40;
	const GAME_S32 m_s32GridCount = GAME_CELL_COUNT;
	GAME_DOUBLE m_dLastUpdateTime = 0;
	GAME_BOOL m_bCanPressKey = true;
	SNAKE_DIRECTION m_enNextMove = SNAKE_DIRECTION_LEFT;
	GAME_U16 score = 1;

	// Game Entities
	CFood *m_pFood;
	CSnake *m_pSnake;

	// GUI Functions
	void initialize();
	GAME_S32 main_loop();
	void set_background_colour(const Color &bgColour);
	void draw_game();
	void draw_food();
	void draw_snake();
	void read_keyboard_inputs();

	// Game Logic Update
	void update();

	// Function to generate a Vector2 with a random position
	Vector2 generate_random_pos();

	// Function to check if game update interval has passed
	GAME_BOOL update_interval_passed();

	// Function to check if head of snake collided with food entity
	GAME_BOOL food_eaten();

	// Function to generate a new position for the food entity once it's been eaten
	void update_food_pos();

	// Function to check if vFoodPos collides with the
	// body of the snake to help with spawning new food entities
	GAME_BOOL check_snake_food_collision(const Vector2 &vFoodPos);

	
};

#endif // !__SNAKE_GAME_H__

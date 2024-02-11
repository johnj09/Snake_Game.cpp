#include "raylib.h"
#include "snake_game.h"

CSnakeGame::CSnakeGame()
{
	m_pSnake = new CSnake();
	m_pFood = new CFood();
}

CSnakeGame::~CSnakeGame()
{
	if (m_pFood != nullptr)
	{
		delete m_pFood;
		m_pFood = nullptr;
	}

	if (m_pSnake != nullptr)
	{
		delete m_pSnake;
		m_pFood = nullptr;
	}
}

void CSnakeGame::run()
{
	// Initialize window and initial settings
	initialize();

	// Main Loop
	main_loop();

	// Close window after main loop finishes
	CloseWindow();
}

void CSnakeGame::initialize()
{
	InitWindow(m_s32WindowWidth, m_s32WindowHeight, m_pcGameName);
	SetTargetFPS(m_s32TargetFPS);
	m_pFood->set_position(generate_random_pos());
}

GAME_S32 CSnakeGame::main_loop()
{
	while (WindowShouldClose() == false)
	{
		BeginDrawing();

		read_keyboard_inputs();

		if (update_interval_passed())
		{
			update();
		}

		set_background_colour(m_bgColour);

		draw_game();

		EndDrawing();
	}

	return GAME_OK;
}

void CSnakeGame::set_background_colour(const Color &bgColour)
{
	ClearBackground(bgColour);
}

void CSnakeGame::draw_game()
{
	draw_food();
	draw_snake();
}

void CSnakeGame::draw_food()
{
	// Find grid coordinates
	const GAME_FLOAT fPosCol = m_pFood->get_position_x();
	const GAME_FLOAT fPosRow = m_pFood->get_position_y();
	// Find actual coordinates
	const GAME_FLOAT fPosX = fPosCol * m_fGridSize + 6;
	const GAME_FLOAT fPosY = fPosRow * m_fGridSize + 6;

	Image image = m_pFood->get_image();
	Texture2D texture = LoadTextureFromImage(image);

	DrawTexture(texture, (GAME_S32)fPosX, (GAME_S32)fPosY, WHITE);
	//DrawCircle(s32FoodPosX, s32FoodPosY, 0.5 * m_s32GridSize, m_entityColour);
}

void CSnakeGame::draw_snake()
{
	const std::deque<Vector2> vvBodyPos = m_pSnake->get_snake_body();
	const GAME_U32 u32SnakeSize = (GAME_U32) vvBodyPos.size();

	for (GAME_U32 i = 0; i < u32SnakeSize; i++)
	{
		// Find grid coordinates
		const GAME_FLOAT fPosCol = vvBodyPos[i].x;
		const GAME_FLOAT fPosRow = vvBodyPos[i].y;
		// Find actual coordinates
		const GAME_FLOAT fPosX = fPosCol * m_fGridSize;
		const GAME_FLOAT fPosY = fPosRow * m_fGridSize;
		
		Rectangle body = Rectangle{ fPosX, fPosY, m_fGridSize, m_fGridSize };
		DrawRectangleRounded(body, 0.5, 6, m_entityColour);
	}
}

void CSnakeGame::read_keyboard_inputs()
{
	if (IsKeyPressed(KEY_UP))
	{
		m_enNextMove = SNAKE_DIRECTION_UP;
	}
	if (IsKeyPressed(KEY_DOWN))
	{
		m_enNextMove = SNAKE_DIRECTION_DOWN;
	}
	if (IsKeyPressed(KEY_LEFT))
	{
		m_enNextMove = SNAKE_DIRECTION_LEFT;
	}
	if (IsKeyPressed(KEY_RIGHT))
	{
		m_enNextMove = SNAKE_DIRECTION_RIGHT;
	}
}

void CSnakeGame::update()
{
	m_pSnake->update_snake_direction(m_enNextMove);
	m_pSnake->update_snake_body();
	if (food_eaten())
	{
		update_food_pos();
		m_pSnake->increase_snake_size();
		score++;
	}
}

Vector2 CSnakeGame::generate_random_pos()
{
	GAME_FLOAT fPosX = static_cast<GAME_FLOAT>(GetRandomValue(0, GAME_CELL_COUNT - 1));
	GAME_FLOAT fPosY = static_cast<GAME_FLOAT>(GetRandomValue(0, GAME_CELL_COUNT - 1));
	return Vector2{ fPosX, fPosY };
}

GAME_BOOL CSnakeGame::update_interval_passed()
{
	GAME_DOUBLE dCurrentTime = GetTime();
	if (dCurrentTime - m_dLastUpdateTime >= GAME_UPDATE_INTERVAL)
	{
		m_dLastUpdateTime = dCurrentTime;
		return true;
	}

	return false;
}

GAME_BOOL CSnakeGame::food_eaten()
{
	const Vector2 vFoodPos = m_pFood->get_position();
	const Vector2 vSnakeHeadPos = m_pSnake->get_snake_body()[0];
	return Vector2Equals(vFoodPos, vSnakeHeadPos);
}

void CSnakeGame::update_food_pos()
{
	Vector2 vTempPos = generate_random_pos();
	while (!check_snake_food_collision(vTempPos))
	{
		vTempPos = generate_random_pos();
	}
	
	m_pFood->set_position(vTempPos);
}

GAME_BOOL CSnakeGame::check_snake_food_collision(const Vector2 &vFoodPos)
{
	const std::deque<Vector2> dqvTempSnake = m_pSnake->get_snake_body();
	for (GAME_U32 i = 0; i < dqvTempSnake.size(); i++)
	{
		if (Vector2Equals(vFoodPos, dqvTempSnake[i]))
		{
			return false;
		}
	}
	return true;
}
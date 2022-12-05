#pragma once

#include "raylib.h"

#include <vector>

#include "Entity.h"
#include "Player.h"
#include "Cars.h"
#include "Trunks.h"

class Game
{
private:

	Player* player;
	const int size = 10;
	Entity* obstacles[5];

	void Input();

public:

	Game();
	~Game();

	void initGame();
	void updateGame();
	void drawGame();

};


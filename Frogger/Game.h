#pragma once

#include "raylib.h"
#include "Entity.h"
#include "Player.h"
#include "Cars.h"

class Game
{
private:

	Player* player;
	Entity* car[5];

	void Input();

public:

	Game();
	~Game();

	void initGame();
	void updateGame();
	void drawGame();

};


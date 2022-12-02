#pragma once

#include "raylib.h"
#include "Entity.h"
#include "Player.h"


class Game
{
private:

	Player* player;


	void Input();

public:

	Game();
	~Game();

	void initGame();
	void updateGame();
	void drawGame();

};


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
	const int size = 20;
	Entity* obstacles[20];

	std::vector<Rectangle> water_vector;
	int trunksPerRow = 3;
	void Input();
	void createTrunks(int initalIndex);

public:

	Game();
	~Game();

	void initGame();
	void updateGame();
	void drawGame();

};


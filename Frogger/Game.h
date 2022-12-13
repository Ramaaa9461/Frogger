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

	static const int size = 20;
	static const int victoryZonesCount = 5;
	int trunksPerRow = 3;

	Player* player;
	Entity* obstacles[size];

	Rectangle victoryZones[victoryZonesCount];
	Rectangle killZone;
	
	Texture background;
	Texture victoryFrogTexture;
	Font font;

	void Input();
	void createTrunks(int initalIndex);
	void createCars();
	void drawTexts();

public:

	Game();
	~Game();

	void initGame();
	void updateGame();
	void drawGame();

};


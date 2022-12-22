#pragma once

#include "raylib.h"

#include "AssetsImporter.h"
#include "Entity.h"
#include "Player.h"
#include "Cars.h"
#include "Trunks.h"

class Game
{
private:

	AssetsImporter* AI;

	static const int size = 20;
	static const int victoryZonesCount = 5;
	int trunksPerRow = 3;
	int UnlockedVictoriesZonesCount;

	Player* player;
	Entity* obstacles[size];

	Rectangle victoryZones[victoryZonesCount];
	bool unlockedVictoriesZones[victoryZonesCount];
	Rectangle killZone;
	
	Texture background;
	Texture victoryFrogTexture;
	Music gameplayMusic;
	Font font;

	Rectangle pauseButton;
	Sound clickSound;
	int fontSize = 20;

	void Input();
	void createVictoriesZones();
	void createTrunks(int initalIndex);
	void createCars();
	void drawTexts();

public:

	Game();
	~Game();

	void initGame();
	void updateGame();
	void drawGame();
	
	void resetValues();
	Music& getGameplayMusic();
};


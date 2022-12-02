#pragma once

#include "raylib.h"

#include "SceneManager.h"
#include "Menu.h"
#include "Rules.h"
#include "Credits.h"
#include "Game.h"
#include "Pause.h"
#include "EndGame.h"


class GameManager
{
	SceneManager* sceneManager = nullptr;

	Menu* menu;
	Rules* rules;
	Credits* credits;
	Game* game;
	Pause* pause;
	EndGame* endGame;


	void init();

public:
	GameManager();
	~GameManager();

	void run();

};


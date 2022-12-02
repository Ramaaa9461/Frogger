#pragma once

#include "raylib.h"
#include "SceneManager.h"

class GameManager
{

	SceneManager* sceneManager = nullptr;

public:
	GameManager();
	~GameManager();

	void run();

};


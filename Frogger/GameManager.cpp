#include "GameManager.h"

GameManager::GameManager()
{
	sceneManager = new SceneManager();

}

GameManager::~GameManager()
{
	delete sceneManager;

}

void GameManager::run()
{
	InitWindow(800, 450, "Frogger");
	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);

		switch (sceneManager->getCurrentScene())
		{
		case Scene::MENU:
			break;
		case Scene::RULES:
			break;
		case Scene::CREDITS:
			break;
		case Scene::ENDGAME:
			break;
		case Scene::GAME:
			break;
		case Scene::EXIT:
			break;
		}

		EndDrawing();
	}
	CloseWindow();


}

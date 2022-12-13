#include "GameManager.h"

GameManager::GameManager()
{
	sceneManager = SceneManager::getSceneManager();

	menu = new Menu();
	rules = new Rules();
	credits = new Credits();
	game = new Game();
	pause = new Pause;
	endGame = new EndGame();
}

GameManager::~GameManager()
{
	delete sceneManager;

	delete menu;
	delete rules;
	delete credits;
	delete game;
	delete pause;
	delete endGame;
}

void GameManager::run()
{
	InitWindow(800, 720, "Frogger");
	SetTargetFPS(60);
	InitAudioDevice();

	init();



	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);

		switch (sceneManager->getCurrentScene())
		{
		case Scene::MENU:

			menu->updateMenu();
			menu->drawMenu();

			break;
		case Scene::RULES:

			rules->updateRules();
			rules->drawRules();

			break;
		case Scene::CREDITS:
			
			credits->updateCredits();
			credits->drawCredits();
			
			break;
		case Scene::ENDGAME:

			endGame->update();
			endGame->draw();

			break;
		case Scene::GAME:

			game->updateGame();
			game->drawGame();

			break;
		case Scene::EXIT:
			break;
		}

		EndDrawing();
	}
	CloseWindow();

	CloseAudioDevice();
}


void GameManager::init()
{
	game->initGame();
}

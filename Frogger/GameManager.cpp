#include "GameManager.h"

#include "AssetsImporter.h"

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
	delete assetsImporter;

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

	assetsImporter = AssetsImporter::getAssetsImporter();
	menuMusic = assetsImporter->getMenuMusic();
		PlayMusicStream(menuMusic);

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);

		UpdateMusicStream(menuMusic);

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

			if (sceneManager->getResetValues())
			{
				PlayMusicStream(menuMusic);
				endGame->resetValues();
				sceneManager->setResetValues(false);
			}
			endGame->update();
			endGame->draw();

			break;
		case Scene::GAME:

			if (sceneManager->getResetValues())
			{
				StopMusicStream(menuMusic);
				game->resetValues();
				sceneManager->setResetValues(false);
			}
			game->updateGame();
			game->drawGame();

			break;
		case Scene::EXIT:
			//Terminar el juego

			break;
		}

		EndDrawing();
	}

	assetsImporter->deInitAssetImporter();

	CloseWindow();

	CloseAudioDevice();

}


void GameManager::init()
{
	menu->initMenu();
	game->initGame();
	rules->initRules();
	credits->initCredits();
	endGame->initEndGame();

	//pause->initPause();
}

#include "Game.h"

#include "SceneManager.h"

#include <iostream>

Game::Game() {}

Game::~Game()
{
	delete player;
	delete[] obstacles;
}

void Game::initGame()
{
	AI = AssetsImporter::getAssetsImporter();

	background = AI->getBackgroundGameplay();				
	victoryFrogTexture = AI->getVictoryFrog();				
	font = AssetsImporter::getAssetsImporter()->getFont();
	gameplayMusic = AI->getGameplayMusic();					
	PlayMusicStream(gameplayMusic);

	player = new Player();
	
	createVictoriesZones();
	createCars();
	createTrunks(4);

	resetValues();
}

void Game::updateGame()
{
	Input();
	UpdateMusicStream(gameplayMusic);

	for (int i = 0; i < size; i++)
	{
		obstacles[i]->move();
		obstacles[i]->checkCollision(player);
	}

	if (CheckCollisionRecs(killZone, player->getBoxCollider()))
	{
		player->substractLife();
		player->goToInitialPosition();
	}

			UnlockedVictoriesZonesCount = 0;
	for (int i = 0; i < victoryZonesCount; i++)
	{
		if (CheckCollisionRecs(victoryZones[i], player->getBoxCollider()))
		{
			if (!unlockedVictoriesZones[i])
			{
				unlockedVictoriesZones[i] = true;
				player->addFrogPlaced();
				player->goToInitialPosition();
			}
			else
			{
				player->substractLife();
				player->goToInitialPosition();
			}
		}

		if (unlockedVictoriesZones[i])
		{
			UnlockedVictoriesZonesCount++;

			if (UnlockedVictoriesZonesCount == victoryZonesCount)
			{
				SceneManager::getSceneManager()->setPlayerHaveWon(true);
				SceneManager::getSceneManager()->setCurrentScene(Scene::ENDGAME);
			}

		}
	}

	if (player->getLife() <= 0)
	{
		SceneManager::getSceneManager()->setPlayerHaveWon(false);
		SceneManager::getSceneManager()->setCurrentScene(Scene::ENDGAME);
	}
}

void Game::drawGame()
{
	DrawTexture(background, 0, 0, WHITE);

	drawTexts();

	for (int i = 0; i < victoryZonesCount; i++)
	{
		if (unlockedVictoriesZones[i])
		{
			DrawTexture(victoryFrogTexture, victoryZones[i].x, victoryZones[i].y, WHITE);
		}
	}

	for (int i = 0; i < size; i++)
	{
		obstacles[i]->draw();
	}

	player->draw();
}

void Game::resetValues()
{
	PlayMusicStream(gameplayMusic);

	player->goToInitialPosition();
	player->setLife(5);
	player->setFrogPlaced(5);
}

Music& Game::getGameplayMusic()
{
	return gameplayMusic;
}

void Game::Input()
{
	if (IsKeyPressed(KEY_W))
	{
		player->moveUp();
	}

	if (IsKeyPressed(KEY_S))
	{
		player->moveDown();
	}

	if (IsKeyPressed(KEY_A))
	{
		player->moveLeft();
	}

	if (IsKeyPressed(KEY_D))
	{
		player->moveRight();
	}

	if (IsKeyPressed(KEY_P))
	{
		SceneManager::getSceneManager()->setCurrentScene(Scene::PAUSE, false);
	}
}

void Game::createVictoriesZones()
{
	for (int i = 0; i < victoryZonesCount; i++)
	{
		victoryZones[i].width = 150;
		victoryZones[i].height = 100;
		victoryZones[i].y = 0;

		unlockedVictoriesZones[i] = false;
	}

	victoryZones[0].x = 5;
	victoryZones[1].x = 175;
	victoryZones[2].x = GetScreenWidth() / 2 - 55;
	victoryZones[3].x = GetScreenWidth() - victoryFrogTexture.width - 185;
	victoryZones[4].x = GetScreenWidth() - victoryFrogTexture.width - 10;

	killZone.width = GetScreenWidth();
	killZone.height = 70;
	killZone.x = 0;
	killZone.y = 0;
}

void Game::drawTexts()
{
	DrawTextEx(font, "Lifes: ", { 0, (float)GetScreenHeight() - 40 }, 30, 1.5, WHITE);
	DrawTextEx(font, TextFormat("%i", player->getLife()), { (float)MeasureText("Lifes: ", 30), (float)GetScreenHeight() - 40 }, 30, 1.5, WHITE);

	DrawTextEx(font, "Frog Placed: ", { (float)GetScreenWidth() - 235, (float)GetScreenHeight() - 40 }, 30, 1.5, WHITE);
	DrawTextEx(font, TextFormat("%i", player->getFrogPlaced()), { GetScreenWidth() - 250 + (float)MeasureText("Frog Placed:", 30), (float)GetScreenHeight() - 40 }, 30, 1.5, WHITE);
	DrawTextEx(font, "/", { (float)GetScreenWidth() - 40, (float)GetScreenHeight() - 40 }, 30, 1.5, WHITE);
	DrawTextEx(font, TextFormat("%i", victoryZonesCount), { (float)GetScreenWidth() - 25, (float)GetScreenHeight() - 40 }, 30, 1.5, WHITE);
}

void Game::createTrunks(int initalIndex)
{
	int index = initalIndex;
	

	for (int i = 0; i < trunksPerRow; i++)
	{
		index++;
		obstacles[index] = new Trunks(AI->getTrunk(), 6, 1, 10, (GetScreenWidth() / 3) * i);
	}

	for (int i = 0; i < trunksPerRow; i++)
	{
		index++;
		obstacles[index] = new Trunks(AI->getTrunk(), 5, 0, 8, (GetScreenWidth() / 3) * i);
	}

	for (int i = 0; i < trunksPerRow; i++)
	{
		index++;
		obstacles[index] = new Trunks(AI->getTrunk(), 4, 1, 9, (GetScreenWidth() / 3) * i);
	}

	for (int i = 0; i < trunksPerRow; i++)
	{
		index++;
		obstacles[index] = new Trunks(AI->getTrunk(), 3, 0, 5, (GetScreenWidth() / 3) * i);
	}

	for (int i = 0; i < trunksPerRow; i++)
	{
		index++;
		obstacles[index] = new Trunks(AI->getTrunk(), 2, 1, 11, (GetScreenWidth() / 3) * i);
	}
}

void Game::createCars()
{
	obstacles[0] = new Cars(AI->getFireTruck(), 13, 0, 5);
	obstacles[1] = new Cars(AI->getGreenCar(), 12, 1, 7);
	obstacles[2] = new Cars(AI->getYellowCar(), 11, 0, 4);
	obstacles[3] = new Cars(AI->getTruck(), 10, 1, 10);
	obstacles[4] = new Cars(AI->getBlueCar(), 9, 0, 15);
}

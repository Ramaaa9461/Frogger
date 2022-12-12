#include "Game.h"



#include <iostream>

Game::Game() {}

Game::~Game()
{
	delete player;
	delete obstacles;
}

void Game::initGame()
{
	int index = 0;

	player = new Player();
	obstacles[0] = new Cars("res/Images/blueCar.png", 13, 0, 5);
	obstacles[1] = new Cars("res/Images/blueCar.png", 12, 1, 7);
	obstacles[2] = new Cars("res/Images/blueCar.png", 11, 0, 4);
	obstacles[3] = new Cars("res/Images/blueCar.png", 10, 1, 10);
	obstacles[4] = new Cars("res/Images/blueCar.png", 9, 0, 15);

	createTrunks(4);

}

void Game::updateGame()
{
	Input();

	if (CheckCollisionRecs(player->getBoxCollider(), water))
	{
		player->substractLife();
		player->goToInitialPosition();
	}

	for (int i = 0; i < size; i++)
	{
		obstacles[i]->move();
		obstacles[i]->checkCollision(player);
	}

	std::cout << player->getLife() << std::endl;
}

void Game::drawGame()
{
	DrawRectangleRec(water, SKYBLUE);
	for (int i = 0; i < size; i++)
	{
		obstacles[i]->draw();
	}

	player->draw();

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
}

void Game::createTrunks(int initalIndex)
{
	int index = initalIndex;
	for (int i = 0; i < trunksPerRow; i++)
	{
		index++;
		obstacles[index] = new Trunks("res/Images/trunk.png", 6, 1, 10, (GetScreenWidth() / 3) * i);
	}

	for (int i = 0; i < trunksPerRow; i++)
	{
		index++;
		obstacles[index] = new Trunks("res/Images/trunk.png", 5, 0, 8, (GetScreenWidth() / 3) * i);
	}

	for (int i = 0; i < trunksPerRow; i++)
	{
		index++;
		obstacles[index] = new Trunks("res/Images/trunk.png", 4, 1, 9, (GetScreenWidth() / 3) * i);
	}

	for (int i = 0; i < trunksPerRow; i++)
	{
		index++;
		obstacles[index] = new Trunks("res/Images/trunk.png", 3, 0, 5, (GetScreenWidth() / 3) * i);
	}

	for (int i = 0; i < trunksPerRow; i++)
	{
		index++;
		obstacles[index] = new Trunks("res/Images/trunk.png", 2, 1, 11, (GetScreenWidth() / 3) * i);
	}
}

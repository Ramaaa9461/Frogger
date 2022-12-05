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
	player = new Player();
	obstacles[0] = new Cars("res/Images/blueCar.png", 13, 0, 5);
	obstacles[1] = new Cars("res/Images/blueCar.png", 12, 1, 7);
	obstacles[2] = new Cars("res/Images/blueCar.png", 11, 0, 4);
	obstacles[3] = new Cars("res/Images/blueCar.png", 10, 1, 10);
	obstacles[4] = new Trunks("res/Images/trunk.png", 4, 0, 8);
}

void Game::updateGame()
{
	Input();

	for (int i = 0; i < 5; i++)
	{
		obstacles[i]->move();
		obstacles[i]->checkCollision(player);
	}

	std::cout << player->getLife() << std::endl;
}

void Game::drawGame()
{

	for (int i = 0; i < 5; i++)
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

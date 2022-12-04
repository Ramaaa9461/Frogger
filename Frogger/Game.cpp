#include "Game.h"



#include <iostream>

Game::Game() {}

Game::~Game()
{
	delete player;
	delete car;
}

void Game::initGame()
{
	player = new Player();
	car[0] = new Cars("res/Images/blueCar.png", 13, 0, 5);
	car[1] = new Cars("res/Images/blueCar.png", 12, 1, 7);
	car[2] = new Cars("res/Images/blueCar.png", 11, 0, 4);
	car[3] = new Cars("res/Images/blueCar.png", 10, 1, 10);
	car[4] = new Cars("res/Images/blueCar.png", 9, 0, 8);
}

void Game::updateGame()
{
	Input();

	for (int i = 0; i < 5; i++)
	{
		((Cars*)car[i])->move();
		((Cars*)car[i])->checkCollision(player);
	}

	std::cout << player->getLife() << std::endl;
}

void Game::drawGame()
{

	for (int i = 0; i < 5; i++)
	{
		car[i]->draw();
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

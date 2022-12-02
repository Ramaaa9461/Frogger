#include "Game.h"





Game::Game(){}

Game::~Game()
{
	delete player;
}

void Game::initGame()
{
	player = new Player();
}

void Game::updateGame()
{
	Input();


}

void Game::drawGame()
{
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

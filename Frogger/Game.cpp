#include "Game.h"



#include <iostream>

Game::Game() {}

Game::~Game()
{
	delete player;
	delete[] obstacles;
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

	for (int i = 0; i < water_vector.size(); i++)
	{	
		water_vector[i].x = obstacles[i + 5]->getBoxCollider().x;

		if (CheckCollisionRecs(player->getBoxCollider(), water_vector[i]))
		{
			player->substractLife();
			player->goToInitialPosition();
		}
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

	for (int i = 0; i < water_vector.size(); i++)
	{
		DrawRectangleRec(water_vector[i], SKYBLUE);
	}
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
		obstacles[index] = new Trunks("res/Images/trunk.png", 6, 1, 10, (GetScreenWidth() / 3) * i );
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


	//index = initalIndex;

	//for (int i = 0; i < trunksPerRow; i++)
	//{
	//	index++;
	//	Rectangle waterRigth;
	//	Rectangle trunk = obstacles[index]->getBoxCollider();

	//	waterRigth.x = trunk.x + trunk.width;
	//	waterRigth.y = trunk.y;
	//	waterRigth.height = trunk.height;

	//	if (i < 2)
	//	{
	//	waterRigth.width = obstacles[index + 1]->getBoxCollider().x - trunk.x;
	//	}
	//	else
	//	{
	//		waterRigth.width = 266;
	//	}
	//	
	//	
	//	water_vector.push_back(waterRigth);
	//}

	/*for (int i = 0; i < trunksPerRow; i++)
	{
		Rectangle waterRigth;
		index++;

		waterRigth.x = obstacles[index]->getBoxCollider().x + obstacles[index]->getBoxCollider().width;
		waterRigth.y = obstacles[index]->getBoxCollider().y;
		waterRigth.height = obstacles[index]->getBoxCollider().height;
		waterRigth.width = obstacles[index + 1]->getBoxCollider().x - obstacles[index]->getBoxCollider().x;

		water_vector.push_back(waterRigth);
	}

	for (int i = 0; i < trunksPerRow; i++)
	{
		Rectangle waterRigth;
		index++;

		waterRigth.x = obstacles[index]->getBoxCollider().x + obstacles[index]->getBoxCollider().width;
		waterRigth.y = obstacles[index]->getBoxCollider().y;
		waterRigth.height = obstacles[index]->getBoxCollider().height;
		waterRigth.width = obstacles[index + 1]->getBoxCollider().x - obstacles[index]->getBoxCollider().x;

		water_vector.push_back(waterRigth);
	}

	for (int i = 0; i < trunksPerRow; i++)
	{
		Rectangle waterRigth;
		index++;

		waterRigth.x = obstacles[index]->getBoxCollider().x + obstacles[index]->getBoxCollider().width;
		waterRigth.y = obstacles[index]->getBoxCollider().y;
		waterRigth.height = obstacles[index]->getBoxCollider().height;
		waterRigth.width = obstacles[index + 1]->getBoxCollider().x - obstacles[index]->getBoxCollider().x;

		water_vector.push_back(waterRigth);
	}

	for (int i = 0; i < trunksPerRow; i++)
	{
		Rectangle waterRigth;
		index++;

		waterRigth.x = obstacles[index]->getBoxCollider().x + obstacles[index]->getBoxCollider().width;
		waterRigth.y = obstacles[index]->getBoxCollider().y;
		waterRigth.height = obstacles[index]->getBoxCollider().height;
		waterRigth.width = obstacles[index + 1]->getBoxCollider().x - obstacles[index]->getBoxCollider().x;

		water_vector.push_back(waterRigth);
	}*/
}

#include "EndGame.h"

#include "SceneManager.h"
void EndGame::initEndGame()
{
	AI = AssetsImporter::getAssetsImporter();
	background = AI->getBasicBackground();
	font = AI->getFont();

	int sizeX = 250;
	int sizeY = 100;
	setButtons(button1, sizeX, sizeY, -150, 200);
	setButtons(button2, sizeX, sizeY, 150, 200);

	
}

void EndGame::update()
{

	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		if (CheckCollisionPointRec(GetMousePosition(), button1))
		{
			SceneManager::getSceneManager()->setCurrentScene(Scene::GAME);
		}
		else if (CheckCollisionPointRec(GetMousePosition(), button2))
		{
			SceneManager::getSceneManager()->setCurrentScene(Scene::MENU);
		}
	}
}

void EndGame::draw()
{
	DrawTexture(background, 0, 0, WHITE);

	int fontSize = 30;

	DrawTextEx(font, text, { (float)GetScreenWidth() / 2 - MeasureText(text, fontSize) / 2,  350}, fontSize, 1.0f, YELLOW);

	DrawRectangleRec(button1, ORANGE);
	DrawTextEx(font, "Retry", { button1.x + button1.width / 2 - MeasureText("Retry", fontSize) / 2, button1.y + button1.height / 2 - fontSize / 2 }, fontSize,2.0f, RED);
	DrawRectangleRec(button2, ORANGE);
	DrawTextEx(font, "Menu", { button2.x + button2.width / 2 - MeasureText("Menu", fontSize) / 2, button2.y + button1.height / 2 - fontSize / 2 }, fontSize, 2.0f, RED);
}

void EndGame::resetValues()
{
	if (SceneManager::getSceneManager()->getPlayerHaveWon())
	{
		text = "You Win";
	}
	else
	{
		text = "You Lose";
	}
}

void EndGame::setButtons(Rectangle& rectangle, int sizeX, int sizeY, int difWidth, int difHeight)
{
	rectangle.width = sizeX;
	rectangle.height = sizeY;
	rectangle.x = (GetScreenWidth() / 2) - (sizeX / 2) + difWidth;
	rectangle.y = (GetScreenHeight() / 2) - (sizeY / 2) + difHeight;
}

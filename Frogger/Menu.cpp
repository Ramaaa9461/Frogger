#include "Menu.h"

void Menu::setButtons(Rectangle& rectangle, int sizeX, int sizeY, int difWidth, int difHeight)
{
	rectangle.width = sizeX;
	rectangle.height = sizeY;
	rectangle.x = (GetScreenWidth() / 2) - (sizeX / 2) + difWidth;
	rectangle.y = (GetScreenHeight() / 2) - (sizeY / 2) + difHeight;

}

void Menu::initMenu()
{
	AI = AssetsImporter::getAssetsImporter();
	background = AI->getBasicBackground();
	clickSound = AI->getClickSound();
	font = AI->getFont();

	int sizeX = 150;
	int sizeY = 50;
	setButtons(button1, sizeX, sizeY, 0, 0);
	setButtons(button2, sizeX, sizeY, 0, 100);
	setButtons(button3, sizeX, sizeY, 0, 200);
	setButtons(button4, sizeX, sizeY, 0, 300);
}

void Menu::updateMenu()
{
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		if (CheckCollisionPointRec(GetMousePosition(), button1))
		{
			SceneManager::getSceneManager()->setCurrentScene(Scene::GAME);
			PlaySound(clickSound);
		}
		else if (CheckCollisionPointRec(GetMousePosition(), button2))
		{
			SceneManager::getSceneManager()->setCurrentScene(Scene::RULES);
			PlaySound(clickSound);
		}
		else if (CheckCollisionPointRec(GetMousePosition(), button3))
		{
			SceneManager::getSceneManager()->setCurrentScene(Scene::CREDITS);
			PlaySound(clickSound);
		}
		else if (CheckCollisionPointRec(GetMousePosition(), button4))
		{
			SceneManager::getSceneManager()->setCurrentScene(Scene::EXIT);
			PlaySound(clickSound);
		}
	}
}

void Menu::drawMenu()
{
	DrawTexture(background, 0, 0, WHITE);

	int fontSize = 30;

	DrawRectangleRec(button1, ORANGE);
	DrawTextEx(font, "Start", { button1.x + button1.width / 2 - MeasureText("Retry", fontSize) / 2, button1.y + button1.height / 2 - fontSize / 2 }, fontSize, 2.0f, RED);
	DrawRectangleRec(button2, ORANGE);
	DrawTextEx(font, "Rules", { button2.x + button2.width / 2 - MeasureText("Menu", fontSize) / 2, button2.y + button1.height / 2 - fontSize / 2 }, fontSize, 2.0f, RED);
	DrawRectangleRec(button3, ORANGE);
	DrawTextEx(font, "Credits", { button3.x + button3.width / 2 - MeasureText("Credits", fontSize) / 2, button3.y + button1.height / 2 - fontSize / 2 }, fontSize, 2.0f, RED);
	DrawRectangleRec(button4, ORANGE);
	DrawTextEx(font, "Exit", { button4.x + button4.width / 2 - MeasureText("Exit", fontSize) / 2, button4.y + button1.height / 2 - fontSize / 2 }, fontSize, 2.0f, RED);

}

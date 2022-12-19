#include "Credits.h"


void Credits::initCredits()
{
	AI = AssetsImporter::getAssetsImporter();
	background = AI->getCreditsBackground();
	clickSound = AI->getClickSound();
	font = AI->getFont();

	int sizeX = 150;
	int sizeY = 75;
	setButtons(button1, sizeX, sizeY, 0, GetScreenHeight() / 2 - sizeY / 2);
}

void Credits::updateCredits()
{
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		if (CheckCollisionPointRec(GetMousePosition(), button1))
		{
			SceneManager::getSceneManager()->setCurrentScene(Scene::MENU);
			PlaySound(clickSound);
		}
	}
}
void Credits::drawCredits()
{
	DrawTexture(background, 0, 0, WHITE);

	int fontSize = 15;

	float y = 250;

	DrawTextEx(font, "CREATE BY RAMIRO GUZMAN", { (float)GetScreenWidth() / 2 - MeasureText("CREATE BY RAMIRO GUZMAN", fontSize * 2.0f) / 2, y }, fontSize * 2.0f, 5.0f, YELLOW);
	y += 50;
	DrawTextEx(font, "GUI BACKGROUNDS BY LUCAS PICH", { (float)GetScreenWidth() / 2 - MeasureText("GUI BACKGROUNDS BY LUCAS PICH", fontSize * 2.0f) / 2, y }, fontSize * 2.0f, 5.0f, YELLOW);
	y += 50;
	
	DrawTextEx(font, "ART", { (float)GetScreenWidth() / 2 - MeasureText("ART", fontSize * 2.0f) / 2, y }, fontSize * 2.0f, 5.0f, YELLOW);
	y += 30;
	DrawTextEx(font, "FROGGER GAME SPRITES, herrrattentod: http://www.classicgaming.cc/classics/frogger/graphics", { 0, y }, fontSize, 2.0f, SKYBLUE);
	y += 20;
	
	DrawTextEx(font, "MUSIC", { (float)GetScreenWidth() / 2 - MeasureText("MUSIC", fontSize * 2.0f) / 2, y }, fontSize * 2.0f, 5.0f, YELLOW);
	y += 30;
	DrawTextEx(font, "GAMEPLAY MUSIC, tcarisland: https://opengameart.org/content/menu-1", { 0, y }, fontSize, 2.0f, SKYBLUE);
	y += 20;
	
	DrawTextEx(font, "SFX", { (float)GetScreenWidth() / 2 - MeasureText("SFX", fontSize * 2.0f) / 2, y }, fontSize * 2.0f, 5.0f, YELLOW);
	y += 30;
	DrawTextEx(font, "SMILE JUMP EFFECT, KobatoGames: https://opengameart.org/content/slime-jump-effect", { 0, y }, fontSize, 2.0f, SKYBLUE);
	y += 20;
	DrawTextEx(font, "CRASH COLLISION, qubodup: https://opengameart.org/content/crash-collision", { 0, y }, fontSize, 2.0f, SKYBLUE);
	y += 20;

	DrawTextEx(font, "FONTS", { (float)GetScreenWidth() / 2 - MeasureText("FONTS", fontSize * 2.0f) / 2, y }, fontSize * 2.0f, 5.0f, YELLOW);
	y += 30;
	DrawTextEx(font, "JUNGLE ADVENTURER, Tokokoo: https://www.1001fonts.com/jungle-adventurer-font.html", { 0, y }, fontSize, 2.0f, SKYBLUE);
	y += 20;



	DrawRectangleRec(button1, ORANGE);
	DrawTextEx(font, "Menu", { button1.x + button1.width / 2 - MeasureText("Menu", fontSize) / 2, button1.y + button1.height / 2 - fontSize / 2 }, fontSize, 2.0f, RED);

}

void Credits::setButtons(Rectangle& rectangle, int sizeX, int sizeY, int difWidth, int difHeight)
{
	rectangle.width = sizeX;
	rectangle.height = sizeY;
	rectangle.x = (GetScreenWidth() / 2) - (sizeX / 2) + difWidth;
	rectangle.y = (GetScreenHeight() / 2) - (sizeY / 2) + difHeight;
}
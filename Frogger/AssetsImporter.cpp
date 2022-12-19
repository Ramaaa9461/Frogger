#include "AssetsImporter.h"

AssetsImporter* AssetsImporter::assetsImporter = nullptr;


AssetsImporter::AssetsImporter()
{
	initAssetsImporter();
}

AssetsImporter::~AssetsImporter() {}


AssetsImporter* AssetsImporter::getAssetsImporter()
{
	if (assetsImporter == nullptr)
	{
		assetsImporter = new AssetsImporter();
	}

	return assetsImporter;
}

void AssetsImporter::initAssetsImporter()
{
	font = LoadFont("res/Fonts/JungleAdventurer.ttf");

	backgroundGameplay = LoadTexture("res/Images/gameplayBackground.png");
	basicBackground = LoadTexture("res/Images/basicBackground.png");
	rulesBackground = LoadTexture("res/Images/rulesBackground.png");
	pauseBackground = LoadTexture("res/Images/pauseBackground.png");
	creditsBackground = LoadTexture("res/Images/creditsBackground.png");

	blueCar = LoadTexture("res/Images/blueCar.png");
	yellowCar = LoadTexture("res/Images/yellowCar.png");
	greenCar = LoadTexture("res/Images/greenCar.png");
	truck = LoadTexture("res/Images/truck.png");
	fireTruck = LoadTexture("res/Images/fireTruck.png");

	trunk = LoadTexture("res/Images/trunk.png");
	frog = LoadTexture("res/Images/frog.png");
	victoryFrog = LoadTexture("res/Images/CollectedFrog.png");

	gameplayMusic = LoadMusicStream("res/Music/gameplayMusic.wav");
	menuMusic = LoadMusicStream("res/Music/menuMusic.wav");

	jumpSound = LoadSound("res/Sfx/jump.wav");
	clickSound = LoadSound("res/Sfx/clickSound.ogg");
}

void AssetsImporter::deInitAssetImporter()
{
	UnloadFont(font);

	UnloadTexture(backgroundGameplay);
	UnloadTexture(basicBackground);
	UnloadTexture(rulesBackground);

	UnloadTexture(blueCar);
	UnloadTexture(yellowCar);
	UnloadTexture(greenCar);
	UnloadTexture(truck);
	UnloadTexture(fireTruck);
	
	UnloadTexture(trunk);
	UnloadTexture(frog);
	UnloadTexture(victoryFrog);

	UnloadMusicStream(gameplayMusic);
	UnloadMusicStream(menuMusic);

	UnloadSound(jumpSound);


}

Font AssetsImporter::getFont()
{
	return font;
}

Texture AssetsImporter::getBackgroundGameplay()
{
	return backgroundGameplay;
}

Texture AssetsImporter::getBasicBackground()
{
	return basicBackground;
}

Texture AssetsImporter::getCreditsBackground()
{
	return creditsBackground;
}

Texture AssetsImporter::getRulesBackground()
{
	return rulesBackground;
}

Texture AssetsImporter::getPauseBackground()
{
	return pauseBackground;
}

Texture AssetsImporter::getBlueCar()
{
	return blueCar;
}

Texture AssetsImporter::getYellowCar()
{
	return yellowCar;
}

Texture AssetsImporter::getGreenCar()
{
	return greenCar;
}

Texture AssetsImporter::getTruck()
{
	return truck;
}

Texture AssetsImporter::getFireTruck()
{
	return fireTruck;
}

Texture AssetsImporter::getTrunk()
{
	return trunk;
}

Texture AssetsImporter::getFrog()
{
	return frog;
}

Texture AssetsImporter::getVictoryFrog()
{
	return victoryFrog;
}

Music AssetsImporter::getGameplayMusic()
{
	return gameplayMusic;
}

Music AssetsImporter::getMenuMusic()
{
	return menuMusic;
}

Sound AssetsImporter::getJumpSound()
{
	return jumpSound;
}

Sound AssetsImporter::getClickSound()
{
	return clickSound;
}











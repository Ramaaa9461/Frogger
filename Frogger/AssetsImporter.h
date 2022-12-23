#pragma once

#include "raylib.h"

class AssetsImporter
{
private:

	AssetsImporter();

	static AssetsImporter* assetsImporter;

	Font font;

	Texture backgroundGameplay;
	Texture basicBackground;
	Texture rulesBackground;
	Texture pauseBackground;
	Texture creditsBackground;

	Texture blueCar;
	Texture yellowCar;
	Texture greenCar;
	Texture truck;
	Texture fireTruck;

	Texture trunk;
	Texture frog;
	Texture victoryFrog;

	Music   gameplayMusic;
	Music   menuMusic;

	Sound   jumpSound;
	Sound clickSound;
	Sound loseSound;

public:

	~AssetsImporter();

	static AssetsImporter* getAssetsImporter();

	void initAssetsImporter();
	void deInitAssetImporter();
	Font getFont();

	Texture getBackgroundGameplay();
	Texture getBasicBackground();
	Texture getRulesBackground();
	Texture getPauseBackground();
	Texture getCreditsBackground();

	Texture getBlueCar();
	Texture getYellowCar();
	Texture getGreenCar();
	Texture getTruck();
	Texture getFireTruck();
	Texture getTrunk();
	Texture getFrog();
	Texture getVictoryFrog();

	Music getGameplayMusic();
	Music getMenuMusic();

	Sound getJumpSound();
	Sound getClickSound();
	Sound getLoseSound();


};


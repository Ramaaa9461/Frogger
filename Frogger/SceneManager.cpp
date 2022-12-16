#include "SceneManager.h"

SceneManager* SceneManager::sceneManager = nullptr;

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{

}

SceneManager* SceneManager::getSceneManager()
{
	if (sceneManager == nullptr) {
		sceneManager = new SceneManager();
	}

	return sceneManager;
}

Scene SceneManager::getCurrentScene()
{
	return scene;
}

void SceneManager::setCurrentScene(Scene scene)
{
	resetValues = true;
	this->scene = scene;
}

void SceneManager::setPlayerHaveWon(bool haveWon)
{
	playerHaveWon = haveWon;
}

bool SceneManager::getPlayerHaveWon()
{
	return playerHaveWon;
}

void SceneManager::setResetValues(bool reset)
{
	resetValues = reset;
}

bool SceneManager::getResetValues()
{
	return resetValues;
}




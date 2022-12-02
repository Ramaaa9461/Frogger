#include "SceneManager.h"

SceneManager::SceneManager()
{
	scene = Scene::MENU;
}

SceneManager::~SceneManager()
{

}

Scene SceneManager::getCurrentScene()
{
	return scene;
}

void SceneManager::setCurrentScene(Scene scene)
{
	this->scene = scene;
}


#pragma once

enum class Scene { MENU = 1, GAME, RULES, CREDITS, PAUSE , ENDGAME, EXIT };

class SceneManager
{
private:

	SceneManager();
	Scene scene = Scene::MENU;
	static SceneManager* sceneManager;
	bool playerHaveWon;
	bool resetValues;

public:
	~SceneManager();

	static SceneManager* getSceneManager();

	Scene getCurrentScene();

	void setCurrentScene(Scene _scene);
	void setCurrentScene(Scene _scene, bool resetValues);


	 void setPlayerHaveWon(bool haveWon);
	 bool getPlayerHaveWon();

	 void setResetValues(bool reset);
	 bool getResetValues();
};


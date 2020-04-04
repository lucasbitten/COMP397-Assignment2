#include "GameOverScene.h"
#include <algorithm>
#include "Game.h"
#include "GameManager.h"
#include "glm/gtx/string_cast.hpp"

GameOverScene::GameOverScene()
{
	GameOverScene::start();
}

GameOverScene::~GameOverScene()
= default;

void GameOverScene::draw()
{
	m_label->draw();
	m_score->draw();
	m_enemiesDestroyed->draw();
	m_tryAgain->draw();
}

void GameOverScene::update()
{
}

void GameOverScene::clean()
{

	removeAllChildren();
}

void GameOverScene::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			TheGame::Instance()->quit();
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				TheGame::Instance()->quit();
				break;
			case SDLK_1:
				TheGame::Instance()->changeSceneState(SceneState::LEVEL1_SCENE);
				break;
			case SDLK_2:
				TheGame::Instance()->changeSceneState(SceneState::START_SCENE);
				break;
			}
			break;
		default:
			break;
		}
	}
}

void GameOverScene::start()
{
	const SDL_Color blue = { 0, 0, 255, 255 };
	m_label = new Label("GAME OVER", "Dock51", 80, blue, glm::vec2(400.0f, 40.0f));
	m_label->setParent(this);
	addChild(m_label);

	m_score = new Label("Score: " + std::to_string(GameManager::Instance()->getScore()), "Dock51", 40, blue, glm::vec2(400.0, 275.0f), 0, true);
	m_score->setParent(this);
	addChild(m_score);


	m_enemiesDestroyed = new Label("Enemies Destroyed: " + std::to_string(GameManager::Instance()->getEnemiesDestroyed()) + "/" + std::to_string(GameManager::Instance()->getEnemiesCount()), "Dock51", 40, blue, glm::vec2(400.0f, 325.0f), 0, true);
	m_enemiesDestroyed->setParent(this);
	addChild(m_enemiesDestroyed);

	m_tryAgain = new Label("Press 1 to try again!", "Dock51", 40, blue, glm::vec2(400.0f, 500.0f), 0, true);
	m_tryAgain->setParent(this);
	addChild(m_tryAgain);
	
}

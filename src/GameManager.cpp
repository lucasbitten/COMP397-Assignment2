#include "GameManager.h"

GameManager* GameManager::s_pInstance = nullptr;


int GameManager::getScore()
{
	return m_score;
}

void GameManager::addScore(int score)
{
	m_score += score;
}

GameManager::GameManager(){

}

GameManager::~GameManager()
= default;



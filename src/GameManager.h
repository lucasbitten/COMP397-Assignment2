#pragma once
#ifndef __GAME_MANAGER__
#define __GAME_MANAGER__



class GameManager
{
public:
	static GameManager* Instance()
	{
		if (s_pInstance == nullptr)
		{
			s_pInstance = new GameManager();
			return  s_pInstance;
		}

		return s_pInstance;
	}

	int getScore();
	void addScore(int score);
	

private:

	int m_score = 0;

	GameManager();
	~GameManager();


	static  GameManager* s_pInstance;

};

typedef  GameManager TheGameManager;

#endif

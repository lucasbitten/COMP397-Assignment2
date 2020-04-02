#pragma once
#ifndef __BULLET_MANAGER__
#define __BULLET_MANAGER__

#include <list>
#include "Bullet.h"

class BulletManager
{
public:
	static BulletManager* Instance()
	{
		if (s_pInstance == nullptr)
		{
			s_pInstance = new BulletManager();
			return  s_pInstance;
		}

		return s_pInstance;
	}

	void clean();
	void update();
	void draw();
	Bullet* getBullet();

private:

	BulletManager();
	~BulletManager();

	int m_bulletNumber;
	bool m_isActive;

	void m_buildBulletPool();

	static  BulletManager* s_pInstance;

	std::list<Bullet*> m_pBulletPool;
};

#endif

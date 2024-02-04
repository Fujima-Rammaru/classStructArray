#pragma once
#include"Vector2.h"
#include"Novice.h"

static const int BULLET_NUM_MAX = 256;
class Bullet {

public:

	Bullet();

	void Update();

	void Draw();

public:


	struct ellipse {
		int halfWidth;
		int halfHeight;
		Vector2 center;
		Vector2 leftT;
		Vector2 rightT;
		Vector2 leftB;
		Vector2 rightB;
		Vector2 speed;
		int Texture;
		bool isAppear;
		Vector2 velocity;
		float rad;
		int bulletSurvivalTimer;
	};

	ellipse pBullet[BULLET_NUM_MAX];
	
	int bulletCoolTimer = 20;

};

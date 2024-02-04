#include "Bullet.h"


Bullet::Bullet()
{
	for (int i = 0; i < BULLET_NUM_MAX; i++) {
		pBullet[i].halfWidth = 10;
		pBullet[i].halfHeight = 10;
		pBullet[i].center.x = 0;
		pBullet[i].center.y = 0;

		pBullet[i].isAppear = false;
		pBullet[i].leftT.x = 0;
		pBullet[i].leftT.y = 0;

		pBullet[i].rightT.x = 0;
		pBullet[i].rightT.y = 0;

		pBullet[i].leftB.x = 0;
		pBullet[i].leftB.y = 0;

		pBullet[i].rightB.x = 0;
		pBullet[i].rightB.y = 0;

		pBullet[i].speed.x = 0;
		pBullet[i].speed.y = 0;
		pBullet[i].Texture = Novice::LoadTexture("white1x1.png");

		pBullet[i].velocity.x = 0;
		pBullet[i].velocity.y = 0;
		pBullet[i].rad = 0;
		pBullet[i].bulletSurvivalTimer = 180;
	}
}

void Bullet::Update() {}

void Bullet::Draw()
{
	for (int i = 0; i < BULLET_NUM_MAX; i++) {
		if (pBullet[i].isAppear) {
			Novice::DrawQuad(
				(int)pBullet[i].leftT.x,
				(int)pBullet[i].leftT.y,
				(int)pBullet[i].rightT.x,
				(int)pBullet[i].rightT.y,
				(int)pBullet[i].leftB.x,
				(int)pBullet[i].leftB.y,
				(int)pBullet[i].rightB.x,
				(int)pBullet[i].rightB.y,

				0, 0, 1, 1, pBullet[i].Texture, BLUE);
		}

	}
}

#include "Player.h"

Player::Player(int halfWidth, int halfHeight, Vector2 pos, Vector2 speed)
{
	charactor.halfHeight_ = halfHeight;
	charactor.halfWidth_ = halfWidth;
	charactor.center_.x = pos.x;
	charactor.center_.y = pos.y;
	charactor.speed_.x = speed.x;
	charactor.speed_.y = speed.y;
	charactor.tx = Novice::LoadTexture("white1x1.png");
	respawnTimer = 120;

	for (int i = 0; i < BULLET_NUM_MAX; i++) {
		bullet_.pBullet[i].halfWidth = 10;
		bullet_.pBullet[i].halfHeight = 10;
		bullet_.pBullet[i].center.x = 0;
		bullet_.pBullet[i].center.y = 0;
		bullet_.pBullet[i].isAppear = false;
		bullet_.pBullet[i].leftT.x = 0;
		bullet_.pBullet[i].leftT.y = 0;
		bullet_.pBullet[i].rightT.x = 0;
		bullet_.pBullet[i].rightT.y = 0;
		bullet_.pBullet[i].leftB.x = 0;
		bullet_.pBullet[i].leftB.y = 0;
		bullet_.pBullet[i].rightB.x = 0;
		bullet_.pBullet[i].rightB.y = 0;
		bullet_.pBullet[i].speed.x = 0;
		bullet_.pBullet[i].speed.y = 8;
		bullet_.pBullet[i].Texture = Novice::LoadTexture("white1x1.png");
		bullet_.pBullet[i].velocity.x = 0;
		bullet_.pBullet[i].velocity.y = 0;
		bullet_.pBullet[i].rad = 0;
		bullet_.pBullet[i].bulletSurvivalTimer = 180;
	}
}

void Player::Update(char* keys, char* preKeys)
{
	charactor.leftT.x = charactor.center_.x - charactor.halfWidth_;
	charactor.leftT.y = charactor.center_.y - charactor.halfHeight_;
	charactor.rightT.x = charactor.center_.x + charactor.halfWidth_;
	charactor.rightT.y = charactor.center_.y - charactor.halfHeight_;
	charactor.leftB.x = charactor.center_.x - charactor.halfWidth_;
	charactor.leftB.y = charactor.center_.y + charactor.halfHeight_;
	charactor.rightB.x = charactor.center_.x + charactor.halfWidth_;
	charactor.rightB.y = charactor.center_.y + charactor.halfHeight_;

	if (isAlive_ == false) {
		respawnTimer--;
	}

	if (respawnTimer <= 0) {
		isAlive_ = true;
		respawnTimer = 120;
	}

	if (isAlive_ == true) {

		if (keys[DIK_A]) {
			charactor.center_.x -= charactor.speed_.x;
		}
		if (keys[DIK_D]) {
			charactor.center_.x += charactor.speed_.x;
		}
		if (keys[DIK_W]) {
			charactor.center_.y -= charactor.speed_.y;
		}
		if (keys[DIK_S]) {
			charactor.center_.y += charactor.speed_.y;
		}

		if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
			for (int i = 0; i < BULLET_NUM_MAX; i++) {
				if (bullet_.pBullet[i].isAppear == false) {
					bullet_.pBullet[i].isAppear = true;

					bullet_.pBullet[i].center.x = charactor.center_.x;
					bullet_.pBullet[i].center.y = charactor.center_.y;

					break;
				}
			}
		}

		for (int i = 0; i < BULLET_NUM_MAX; i++) {
			if (bullet_.pBullet[i].isAppear) {
				bullet_.pBullet[i].leftT.x = bullet_.pBullet[i].center.x - 10;
				bullet_.pBullet[i].leftT.y = bullet_.pBullet[i].center.y - 10;
				bullet_.pBullet[i].rightT.x = bullet_.pBullet[i].center.x + 10;
				bullet_.pBullet[i].rightT.y = bullet_.pBullet[i].center.y - 10;
				bullet_.pBullet[i].leftB.x = bullet_.pBullet[i].center.x - 10;
				bullet_.pBullet[i].leftB.y = bullet_.pBullet[i].center.y + 10;
				bullet_.pBullet[i].rightB.x = bullet_.pBullet[i].center.x + 10;
				bullet_.pBullet[i].rightB.y = bullet_.pBullet[i].center.y + 10;

				bullet_.pBullet[i].center.y -= bullet_.pBullet[i].speed.y;

				if (bullet_.pBullet[i].center.y < -200) {
					bullet_.pBullet[i].isAppear = false;
				}
			}
		}
	}
}

void Player::Draw() {
	if (isAlive_) {
		Novice::DrawQuad(
			(int)charactor.leftT.x,
			(int)charactor.leftT.y,
			(int)charactor.rightT.x,
			(int)charactor.rightT.y,
			(int)charactor.leftB.x,
			(int)charactor.leftB.y,
			(int)charactor.rightB.x,
			(int)charactor.rightB.y, 0, 0, 1, 1, charactor.tx, WHITE
		);
		bullet_.Draw();
	}



}

void Player::SetFlag(bool isAlive)
{
	isAlive_ = isAlive;
}

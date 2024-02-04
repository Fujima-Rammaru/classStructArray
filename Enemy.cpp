#include "Enemy.h"
#include"Novice.h"
#include"Player.h"

Enemy::Enemy(int halfWidth, int halfHeight, Vector2 center, Vector2 speed)
{
	charactor2.halfWidth_ = halfWidth;
	charactor2.halfHeight_ = halfHeight;
	charactor2.center_.x = center.x;
	charactor2.center_.y = center.y;
	charactor2.speed_.x = speed.x;
	charactor2.speed_.y = speed.y;
	charactor2.tx = Novice::LoadTexture("white1x1.png");
	respawnTimer = 120;
}

void Enemy::Update() {
	if (isAlive_ == false) {
		respawnTimer--;
	}

	if (respawnTimer <= 0) {
		isAlive_ = true;
		
		respawnTimer = 120;
	}

	if (isAlive_) {
		charactor2.leftT.x = charactor2.center_.x - charactor2.halfWidth_;
		charactor2.leftT.y = charactor2.center_.y - charactor2.halfHeight_;
		charactor2.rightT.x = charactor2.center_.x + charactor2.halfWidth_;
		charactor2.rightT.y = charactor2.center_.y - charactor2.halfHeight_;
		charactor2.leftB.x = charactor2.center_.x - charactor2.halfWidth_;
		charactor2.leftB.y = charactor2.center_.y + charactor2.halfHeight_;
		charactor2.rightB.x = charactor2.center_.x + charactor2.halfWidth_;
		charactor2.rightB.y = charactor2.center_.y + charactor2.halfHeight_;

		charactor2.center_.x += charactor2.speed_.x;
		charactor2.center_.y += charactor2.speed_.y;

		if (charactor2.center_.x < charactor2.halfWidth_) {
			charactor2.speed_.x *= -1;
		}
		else if (charactor2.center_.x > 1280 - charactor2.halfWidth_) {
			charactor2.speed_.x *= -1;
		}

		if (charactor2.center_.y < charactor2.halfHeight_) {
			charactor2.speed_.y *= -1;
		}
		else if (charactor2.center_.y > 720 - charactor2.halfHeight_) {
			charactor2.speed_.y *= -1;
		}
	}


}

void Enemy::Draw()
{
	if (isAlive_) {
		Novice::DrawQuad(
			(int)charactor2.leftT.x,
			(int)charactor2.leftT.y,
			(int)charactor2.rightT.x,
			(int)charactor2.rightT.y,
			(int)charactor2.leftB.x,
			(int)charactor2.leftB.y,
			(int)charactor2.rightB.x,
			(int)charactor2.rightB.y, 0, 0, 1, 1, charactor2.tx, RED

		);
	}
}

void Enemy::SetFlag(bool isAlive)
{
	isAlive_ = isAlive;
}


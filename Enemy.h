#pragma once
#include "Vector2.h"
#include"Player.h"


class Enemy {



public:
	Enemy(int halfWidth, int halfHeight, Vector2 center, Vector2 speed);
	void Update();
	void Draw();
	void hitBox();

	Vector2 GetLeftT() { return charactor2.leftT; };
	Vector2 GetRightB() { return charactor2.rightB; };
	bool GetIsAlive() { return isAlive_; };
	void SetFlag(bool isAlive);
private:

	struct Quad {
		int halfWidth_;
		int halfHeight_;
		Vector2 center_;
		Vector2 leftT;
		Vector2 rightT;
		Vector2 leftB;
		Vector2 rightB;
		Vector2 speed_;
		int tx;
	};
	Quad charactor2;
	bool isAlive_ = true;
	int respawnTimer;
};
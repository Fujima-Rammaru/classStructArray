#pragma once
#include"Novice.h"
#include"Vector2.h"
#include"Bullet.h"

class Player {

public:
	Player(int halfWidth,int halfHeight,Vector2 pos,Vector2 speed );
	void Update(char* keys,char* preKeys);
	void Draw();

	Vector2 GetLeftT() { return charactor.leftT; };
	Vector2 GetrightB() { return charactor.rightB; };
	bool GetIsAlive() { return isAlive_; };
	void SetFlag(bool isAlive);

public:
	Bullet bullet_;

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
	int respawnTimer;
	Quad charactor;
	bool isAlive_=true;
};


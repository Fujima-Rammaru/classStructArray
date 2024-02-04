#include <Novice.h>
#include"Player.h"
#include"Bullet.h"
#include"Enemy.h"

const char kWindowTitle[] = "GC1C_13_フジマ_ランマル_タイトル";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	enum Scene {
		TITLE,
		PLAY,
	};

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);


	Player* player = new Player(50, 50, { 640, 360 }, { 5,5 });
	Enemy* enemy = new Enemy(30, 30, { 640,100 }, { 7,5 });

	Vector2 playerLeftT;
	Vector2 playerRightB;
	Vector2 enemyLeftT;
	Vector2 enemyRightB;
	bool isAliveEnemy;
	bool isAlivePlayer;

	int titleTx = Novice::LoadTexture("./Resources/title.png");

	int sceneNumber = 0;
	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
	
		switch (sceneNumber) {
		case TITLE:
			if (keys[DIK_RETURN]&&preKeys[DIK_RETURN]==0) {
				sceneNumber = PLAY;
			}
			break;


		case PLAY:
			if (keys[DIK_T] && preKeys[DIK_T] == 0) {
				sceneNumber =TITLE;
			}
			player->Update(keys, preKeys);
			enemy->Update();

			playerLeftT = player->GetLeftT();
			playerRightB = player->GetrightB();
			enemyLeftT = enemy->GetLeftT();
			enemyRightB = enemy->GetRightB();
			isAliveEnemy = enemy->GetIsAlive();
			isAlivePlayer = player->GetIsAlive();

			//プレイヤーと敵の当たり判定
			if (isAliveEnemy) {
				if (playerLeftT.x < enemyRightB.x && enemyLeftT.x < playerRightB.x) {
					if (playerLeftT.y < enemyRightB.y && enemyLeftT.y < playerRightB.y) {
						player->SetFlag(false);
					}
				}
			}
			
			//敵とプレイヤーの弾の当たり判定
			for (int i = 0; i < 256; i++) {
				if (player->bullet_.pBullet[i].leftT.x < enemyRightB.x && enemyLeftT.x < player->bullet_.pBullet[i].rightB.x) {
					if (player->bullet_.pBullet[i].leftT.y < enemyRightB.y && enemyLeftT.y < player->bullet_.pBullet[i].rightB.y) {
						enemy->SetFlag(false);
					
					}
				}
				
			}
			break;
		}
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		switch (sceneNumber) {
		case TITLE: 
			Novice::DrawSprite(0, 0, titleTx, 1, 1, 0.0f, WHITE);
			break;

		case PLAY:
			Novice::DrawBox(0, 0, 1280, 720, 0.0f, BLACK, kFillModeSolid);
			Novice::ScreenPrintf(0, 0, "TITLE:T");
			player->Draw();
			enemy->Draw();
			break;
		}
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}
	delete player;
	delete enemy;
	// ライブラリの終了
	Novice::Finalize();
	return 0;
}

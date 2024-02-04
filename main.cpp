#include <Novice.h>
#include"scene.h"
const char kWindowTitle[] = "LC1B_29_ヤラ_チョウセイ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	
	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);
	scene* Scene = new scene;
	// キー入力結果を受け取る箱
	//char keys[256] = { 0 };
	//char preKeys[256] = { 0 };

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();
		
		// キー入力を受け取る
		memcpy(Scene->preKeys, Scene->keys, 256);
		Novice::GetHitKeyStateAll(Scene->keys);

		///
		/// ↓更新処理ここから
		///
		Scene->Updata();

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		Scene->Draw();
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (Scene->preKeys[DIK_ESCAPE] == 0 && Scene->keys[DIK_ESCAPE] != 0) {
			break;
		}
		
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}

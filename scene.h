#pragma once
#include"Player.h"
#include"Enemy.h"
enum Scene{
	TITLE,
	GAME,
	GAMEOVER,
	CLEAR,
};
class scene
{
private:
	int nowscene_;
	int title;
	int font1;
	int font2;
	int font3;
	int BG;
public:
	scene();
	~scene();
	void Updata();
	void Draw();
	Player* player;
	Enemy* enemy[2];
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };
};


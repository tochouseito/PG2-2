#include "scene.h"

#include<iostream>

scene::scene() {
	nowscene_ = TITLE;
	player = new Player;
	//Enemy* enemy[2];
	enemy[0] = new Enemy(100, 500);
	enemy[1] = new Enemy(800, 200);
	title = Novice::LoadTexture("./resouce/PGtitle.png");
	 font1=Novice::LoadTexture("./resouce/start font.png");
	font2 = Novice::LoadTexture("./resouce/gameoverfont.png");
	 font3 = Novice::LoadTexture("./resouce/clearfont.png");
	 BG = Novice::LoadTexture("./resouce/PGBG.png");
}
scene::~scene() {
	
}
void scene::Updata() {
	switch (nowscene_)
	{
	case TITLE:
		player->SetposX(640);
		player->SetposY ( 600);
		player->Setspeed(6);
		player->Setradius(30);
		player->SetshotCT(0);
		player->SetisHit(false);
		enemy[0]->SetposX(100);
		enemy[0]->SetposY( 500);
		enemy[0]->Setspeed(6);
		//enemy[0]->radius_ = 10;
		enemy[0]->Setisalive (true);
		enemy[1]->SetposX(800);
		enemy[1]->SetposY(200);
		enemy[1]->Setspeed(6);
		//enemy[1]->Setradius(10);
		enemy[1]->Setisalive (true);
		for (int i = 0; i < MAX_BULLET; i++) {
			player->bullet[i]->pos_.x = 0;
			player->bullet[i]->pos_.y = 0;
			player->bullet[i]->speed_ = 10;
			player->bullet[i]->isshot = false;
			player->bullet[i]->radius_ = 15;
		}
		if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
			nowscene_ = GAME;
		}
		break;
	case GAME:
		
		player->Update(keys, preKeys);

		enemy[0]->Update();
		enemy[1]->Update();

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < MAX_BULLET; j++) {
				if (enemy[i]->Collision(enemy[i]->Getpos(), player->bullet[j]->pos_
					, enemy[i]->Getradius(), player->bullet[j]->radius_) == true && enemy[i]->Getisalive() == true) {
					enemy[i]->Setisalive(false);
				}

			}
			if (enemy[i]->Collision(enemy[i]->Getpos(), player->Getpos()
				, enemy[i]->Getradius(), player->Getradius()) && player->GetisHit() == false) {

				player->SetisHit(true);
				nowscene_ = GAMEOVER;
			}
		}
		
			if (enemy[0]->Getisalive() == false && enemy[1]->Getisalive() == false) {
				nowscene_ = CLEAR;
			}
			
		
		break;
	case GAMEOVER:
		
		if (keys[DIK_SPACE]&&preKeys[DIK_SPACE]==0) {
			nowscene_ = TITLE;
		}
		break;
	case CLEAR:
		
		if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
			nowscene_ = TITLE;
		}
		break;
	default:

		break;
	}
}
void scene::Draw() {
	switch (nowscene_)
	{
	case TITLE:
		Novice::DrawSprite(0, 0, title, 1.0f, 1.0f, 0.0f, WHITE);
		Novice::DrawSprite(170, 500, font1, 1.0f, 1.0f, 0.0f, WHITE);
		break;
	case GAME:
		Novice::DrawSprite(0, 0, BG, 1.0f, 1.0f, 0.0f, WHITE);
		player->Draw();
		enemy[0]->Draw();
		enemy[1]->Draw();
		break;
	case GAMEOVER:
		Novice::DrawBox(0, 0, 1280, 720, 0.0f, BLACK, kFillModeSolid);
		Novice::DrawSprite(170, 500, font2, 1.0f, 1.0f, 0.0f, WHITE);
		break;
	case CLEAR:
		Novice::DrawBox(0, 0, 1280, 720, 0.0f, BLACK, kFillModeSolid);
		Novice::DrawSprite(170, 500, font3, 1.0f, 1.0f, 0.0f, WHITE);
		break;
	default:

		break;
	}
}
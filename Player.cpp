#include "Player.h"

#include<Novice.h>
Player::Player() {
	pos_.x = 640;
	pos_.y = 600;
	speed_ = 6;
	radius_ = 30;
	shotCT_ = 0;
	isHit_ = false;
	for (int i = 0; i < MAX_BULLET; i++) {
		bullet[i] = new Bullet;
	}
	P= Novice::LoadTexture("./resouce/player.png");
	
}
Player::~Player() {
	for (int i = 0; i < MAX_BULLET; i++) {
		delete bullet[i];
	}
}
void Player::Update(char* keys, char* prekeys) {

	if (keys[DIK_W]) {
		pos_.y += speed_ * (-1);

	}
	if (keys[DIK_S]) {
		pos_.y += speed_;

	}
	if (keys[DIK_A]) {
		pos_.x += speed_ * (-1);

	}

	if (keys[DIK_D]) {
		pos_.x += speed_;

	}
	if (keys[DIK_SPACE] && prekeys[DIK_SPACE] == 0 && shotCT_ <= 0) {
		shotCT_ = SHOTCT;
		for (int i = 0; i < MAX_BULLET; i++) {
			if (bullet[i]->isshot == false) {
				bullet[i]->isshot = true;
				bullet[i]->pos_.x = pos_.x;
				bullet[i]->pos_.y = pos_.y;
				break;
			}
		}
	}
	if (shotCT_ > 0) {
		shotCT_ -= 1;
	}
	for (int i = 0; i < MAX_BULLET; i++) {
		if (bullet[i]->isshot == true) {
			bullet[i]->Update();
		}

	}
}
void Player::Draw() {
	Novice::DrawSprite(pos_.x - radius_, pos_.y - radius_, P, 1.0f, 1.0f, 0.0f, WHITE);
	//Novice::DrawEllipse(pos_.x, pos_.y, radius_, radius_,
	//	0.0f, GREEN, kFillModeSolid);
	for (int i = 0; i < MAX_BULLET; i++) {
		if (bullet[i]->isshot == true) {
			bullet[i]->Draw();
		}
	}
}
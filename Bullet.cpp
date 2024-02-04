#include "Bullet.h"
Bullet::Bullet() {
	pos_.x = 0;
	pos_.y = 0;
	speed_ = 10;
	isshot = false;
	radius_ = 15;
	B = Novice::LoadTexture("./resouce/flame.png");
}
Bullet::~Bullet() {

}
void Bullet::Update() {
	pos_.y -= speed_;
	if (pos_.y <= 0) {
		isshot = false;
	}
}
void Bullet::Draw() {
	Novice::DrawSprite(pos_.x - radius_, pos_.y - radius_, B, 1.0f, 1.0f, 0.0f, WHITE);
	//Novice::DrawEllipse(pos_.x, pos_.y, radius_, radius_,
	//	0.0f, WHITE, kFillModeSolid);
}
#include "Enemy.h"
Enemy::Enemy(int posX, int posY) {

	pos_.x = posX;
	pos_.y = posY;
	speed_ = 6;
	radius_ = 30;
	isalive = true;
	respowntime = respown;
	E=  Novice::LoadTexture("./resouce/Eye boss.png");
}
Enemy::~Enemy() {

}
void Enemy::Update() {
	if (isalive == true) {
		pos_.x += speed_;
		//posY_ += speedY_;

		if (pos_.x - radius_ <= 0 || pos_.x + radius_ >= 1280) {
			speed_ *= -1;
		}
		if (pos_.y - radius_ <= 0 || pos_.y + radius_ >= 720) {
			speed_ *= -1;
		}
	}
	if (respowntime > 0 && isalive == false) {
		respowntime--;
	}
	if (respowntime<=0) {
		isalive = true;
		respowntime = respown;
	}
	
}
void Enemy::Draw() {
	if (isalive == true) {
		Novice::DrawSprite(pos_.x - radius_, pos_.y - radius_, E, 1.0f, 1.0f, 0.0f, WHITE);
		//Novice::DrawEllipse(pos_.x, pos_.y, radius_, radius_, 0.0f, RED, kFillModeSolid);
	}
}
bool Enemy::Collision(Vector2int a, Vector2int b, int radius_a, int radius_b) {
	int A = (a.x - b.x);
	int B = (a.y - b.y);
	int distance = int(sqrtf(float(A * A + B * B)));
	if (distance <= radius_a + radius_b) {
		return true;
	}
	else
	{
		return false;
	}
}
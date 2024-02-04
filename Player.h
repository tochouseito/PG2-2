#pragma once
#include<Vector2.h>
#include"Bullet.h"
#define SHOTCT (20)
#define MAX_BULLET (10)
class Player
{
private:
	Vector2int pos_;
	int speed_;
	int radius_;
	int shotCT_;
	bool isHit_;
	int P;
	//int B;
public:
	
	Player();
	~Player();
	void Update(char* keys, char* prekeys);
	void Draw();
	Bullet* bullet[MAX_BULLET];
	int GetposX() { return pos_.x; };
	int GetposY() {	return pos_.y;};
	Vector2int Getpos() { return pos_; };
	int Getspeed() { return speed_; };
	int Getradius() { return radius_; };
	int GetshotCT() { return shotCT_; };
	bool GetisHit() { return isHit_; };
	void SetposX(int posX) { pos_.x = posX; }
	void SetposY(int posY) { pos_.y = posY; }
	void Setspeed(int Speed) { speed_ = Speed; }
	void SetshotCT(int ShotCT) { shotCT_ = ShotCT; }
	void SetisHit(bool ishit) { isHit_ = ishit; }
	void Setradius(int radiu) { radius_ = radiu; };
};
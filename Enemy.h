#pragma once
#include"Vector2.h"
#include"Novice.h"
#define _USE_MATH_DEFINES
#include <math.h>
#define respown (60)
class Enemy
{
private:
	Vector2int pos_;
	int speed_;
	int radius_;
	bool isalive;
	int respowntime;
	int E;
public:
	
	Enemy(int posX, int posY);
	~Enemy();
	void Update();
	void Draw();
	bool Collision(Vector2int a, Vector2int b, int radius_a, int radius_b);
	int GetposX() { return pos_.x; };
	int GetposY() { return pos_.y; };
	Vector2int Getpos() { return pos_; };
	int Getspeed() { return speed_; };
	int Getradius() { return radius_; };
	bool Getisalive() { return isalive; };
	void SetposX(int posX) { pos_.x = posX; }
	void SetposY(int posY) { pos_.y = posY; }
	void Setspeed(int Speed) { speed_ = Speed; }
	void Setisalive(bool isAlive) { isalive = isAlive; }
	int Gettime() { return respowntime; };
	void Settime(int time) { respowntime = time; }
};

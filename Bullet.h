#pragma once
#include"Vector2.h"
#include"Novice.h"
class Bullet
{
public:
	Vector2int pos_;
	int speed_;
	bool isshot;
	int radius_;
	int B;
	Bullet();
	~Bullet();
	void Update();
	void Draw();
};


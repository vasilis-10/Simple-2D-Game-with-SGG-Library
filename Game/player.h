#pragma once
#include "gameObject.h"
#include "config.h"
#include "enemy.h"

class Player : public GameObject,public Collidable
{
	float speed = 10.0f;
	float pos_x= CANVAS_WIDTH/2, pos_y= CANVAS_HEIGHT/1.2;
	float life = 1.0f;
	float score = 0.0f;
	float size = 65.0f;
public:
	Player(const class Game1 & mygame);
	void update() override;
	void draw() override;
	void init() override;
	Disk getCollisionHull() const override;
	float getRemainingLife() const { return life; }
	void drainLife(float amount) { life = std::max<float>(0.0f, life - amount); }
	float getScore() const { return score; }
	void addScore(float amount) { score = std::max<float>(0.0f, score + amount); }
	float getSize() const { return size; }
	void addSize(float amount) { size = std::max<float>(0.0f, size + amount); }
};

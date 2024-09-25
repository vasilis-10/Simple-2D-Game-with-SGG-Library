#pragma once
#include "gameObject.h"
#include "graphics.h"

class SuperGift : public GameObject, public Collidable
{
	float pos_x, pos_y;
	float speed;
	float size;
	graphics::Brush brush;
	bool activegift = true;

public:
	void update() override;
	void draw()  override;
	void init()  override;
	bool isActivegift() { return activegift; }
	SuperGift(const class Game1& mygame);
	~SuperGift();
	Disk getCollisionHull() const override;

};


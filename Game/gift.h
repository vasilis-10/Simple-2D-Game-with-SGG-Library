#pragma once
#include "gameObject.h"
#include "graphics.h"

class Gift : public GameObject, public Collidable
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
	Gift(const class Game1& mygame);
	~Gift();
	Disk getCollisionHull() const override;

};
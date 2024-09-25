#pragma once
#include "util.h"

class Collidable
{
public:
	virtual Disk getCollisionHull()  const= 0;
};

class GameObject
{
protected:
	const class  Game1& game;
public:
	GameObject(const class Game1 &  mygame);
	virtual void update() = 0;
	virtual void draw() = 0;
	virtual void init() = 0;


};
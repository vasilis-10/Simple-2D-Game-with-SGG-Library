#include "enemy.h"
#include "graphics.h"
#include "config.h"
#include <random>
#include "util.h"
#include "game1.h"
#include "superGift.h"

void SuperGift::update()
{
	pos_y += speed * 0.5 * graphics::getDeltaTime();
	

	if (pos_y > 9 * size)
	{
		activegift = false;
	}
}

void SuperGift::draw()
{
	
	brush.texture = ASSET_PATH + std::string("supergift.png");
	brush.outline_opacity = 0.0f;
	graphics::drawRect(pos_x, pos_y, size, size, brush);
	graphics::resetPose();


	/*collision voithia
	graphics::Brush br;
	br.outline_opacity = 1.0f;
	br.texture = "";
	br.fill_color[0] = 1.0f;
	br.fill_color[1] = 0.3f;
	br.fill_color[2] = 0.3f;
	br.fill_opacity = 0.3f;
	br.gradient = false;
	Disk hull = getCollisionHull();
	graphics::drawDisk(hull.cx, hull.cy, hull.radius, br);
	*/
}

void SuperGift::init()
{
	speed = 0.1f;
	pos_x = CANVAS_WIDTH * rand0to1();
	pos_y = CANVAS_HEIGHT - 520;// +1.1f * size;
	size = 65;
	brush.outline_opacity = 0.0f;
}

SuperGift::SuperGift(const class Game1& mygame)
	: GameObject(mygame)
{
	init();
}

SuperGift::~SuperGift()
{
}

Disk SuperGift::getCollisionHull() const
{
	Disk disk;
	disk.cx = pos_x;
	disk.cy = pos_y;
	disk.radius = size * 0.45f;
	return disk;
}

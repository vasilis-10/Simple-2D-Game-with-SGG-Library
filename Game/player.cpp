#include "player.h"
#include "graphics.h"
#include"game1.h"

Player::Player(const Game1& mygame)
	: GameObject(mygame)
{
}

void Player::update()
{
	if (graphics::getKeyState(graphics::SCANCODE_A))
	{
		pos_x -= speed * graphics::getDeltaTime() / 30.0f;
	}
	if (graphics::getKeyState(graphics::SCANCODE_D))
	{
		pos_x += speed * graphics::getDeltaTime() / 30.0f;
	}
	if (pos_x < 0) pos_x = 0;
	if(pos_x > CANVAS_WIDTH) pos_x = CANVAS_WIDTH;
	if (pos_y < 0) pos_y = 0;
	if (pos_y > CANVAS_HEIGHT) pos_y = CANVAS_HEIGHT ;

}

void Player::draw()
{
	float glow = 0.5f + 0.5f * sinf(graphics::getGlobalTime()/10);
	
	graphics::Brush br;
	br.texture = ASSET_PATH + std::string("basket2.png");
	br.outline_opacity = 0.0f;
	
	graphics::drawRect(pos_x, pos_y, size, size, br);
	

	/*collision voithia
	br.outline_opacity = 1.0f;
	br.texture = "";
	br.fill_color[0] = 0.3f;
	br.fill_color[1] = 1.0f;
	br.fill_color[2] = 0.3f;
	br.fill_opacity = 0.3f;
	br.gradient = false;
	Disk hull = getCollisionHull();
	graphics::drawDisk(hull.cx, hull.cy , hull.radius, br);*/
}

void Player::init()
{
}

Disk Player::getCollisionHull() const
{
	Disk disk;
	disk.cx = pos_x;
	disk.cy = pos_y;
	disk.radius = 35.0f;
	return disk;
}

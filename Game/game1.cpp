#include "game1.h"
#include "graphics.h"
#include "config.h"
#include "player.h"

void Game1::spawnBomb()
{
	if (!bomb)
	{
		bomb = new Enemy(*this);
	}
}

void Game1::checkBomb()
{
	if (bomb && !bomb->isActive())
	{
		delete bomb;
		bomb = nullptr;
	}
}

bool Game1::checkCollision()
{
	if (!player || !bomb)
	{
		return false;
	}
	
	
	Disk d1 = player->getCollisionHull();
	Disk d2 = bomb->getCollisionHull();

	float dx = d1.cx - d2.cx;
	float dy = d1.cy - d2.cy;
	

	if ((sqrt(dx * dx + dy * dy) < d1.radius + d2.radius)) 
	{
		graphics::playSound(std::string(ASSET_PATH) + "bomb.wav", 0.1f);
		player->drainLife(0.1f);
		return true;
	}
	else if (!gift->isActivegift())
	{
		player->drainLife(0.1f);
		return false;
	}
	else
		return false;
}

void Game1::spawnGift()
{
	if (!gift)
	{
		gift = new Gift(*this);
	}
}

void Game1::checkGift()
{
	if (gift && !gift->isActivegift())
	{
		delete gift;
		gift = nullptr;
	}
}

bool Game1::checkCollisionGift()
{
	if (!player || !gift)
	{
		return false;
	}
	
	Disk d1 = player->getCollisionHull();
	Disk d3 = gift->getCollisionHull();

	float dz = d1.cx - d3.cx;
	float dv = d1.cy - d3.cy;
	
	if ((sqrt(dz * dz + dv * dv) < d1.radius + d3.radius))
	{
		graphics::playSound(std::string(ASSET_PATH) + "gift.wav", 0.1f);
		player->addScore(10.0f);
		return true;
	}
	else
		return false;

}

void Game1::spawnSuperGift()
{
	if (!superGift)
	{
		superGift = new SuperGift(*this);
	}
}

void Game1::checkSuperGift()
{
	if (superGift && !superGift->isActivegift())
	{
		delete superGift;
		superGift = nullptr;
	}
}

bool Game1::checkCollisionSuperGift()
{
	if (!player || !superGift)
	{
		return false;
	}

	Disk d1 = player->getCollisionHull();
	Disk d4 = superGift->getCollisionHull();

	float da = d1.cx - d4.cx;
	float db = d1.cy - d4.cy;
	

	if ((sqrt(da * da + db * db) < d1.radius + d4.radius))
	{
		player->addSize(2.0f);
		graphics::playSound(std::string(ASSET_PATH) + "supergift.wav", 0.1f);
		player->addScore(25.0f);
		return true;
	}
	else
		return false;

}

void Game1::updateStartScreen()
{
	if (graphics::getKeyState(graphics::SCANCODE_RETURN))
	{
		status = STATUS_PLAYING;
	}
}

void Game1::updateLevelScreen()
{
	if (!player_initialized && graphics::getGlobalTime() > 1000)
	{
		player = new Player(*this);
		player_initialized = true;
	}

	if (player)
		player->update();

	checkBomb();
	spawnBomb();

	if (bomb)
		bomb->update();
	
	checkGift();
	spawnGift();

	if (gift)
		gift->update();

	checkSuperGift();
	spawnSuperGift();

	if (superGift)
		superGift->update();

	if (checkCollision())
	{
		delete bomb;
		bomb = nullptr;
	}

	if (checkCollisionGift())
	{
		delete gift;
		gift = nullptr;
	}
	
	if (checkCollisionSuperGift())
	{
		delete superGift;
		superGift = nullptr;
	}

	float player_life = player ? player->getRemainingLife() : 0.01f;
	if (player_life <= 0.0f)
	{
		delete bomb;
		bomb = nullptr;
		delete gift;
		gift = nullptr;
		delete superGift;
		superGift = nullptr;
	}
	
}


void Game1::drawStartScreen()
{
	graphics::Brush br;
	
	br.texture = ASSET_PATH + std::string("startback.png");
	br.outline_opacity = 0.0f;
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);


	char info[40];
	sprintf_s(info, "Press ENTER to start");
	br.fill_color[0] = 1.0f;
	graphics::drawText(CANVAS_WIDTH/2, CANVAS_HEIGHT/2, 50, info, br);
}

void Game1::drawLevelScreen()
{
	graphics::Brush br;
	br.texture = ASSET_PATH + std::string("back.png");
	br.outline_opacity = 0.0f;


	//draw background
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);

	// draw player
	if (player)
		player->draw();
	if (bomb)
		bomb->draw();
	if (gift)
		gift->draw();
	if (superGift)
		superGift->draw();

	//life
	float player_life = player ? player->getRemainingLife() : 0.001f;

	br.outline_opacity = 0.0f;
	br.fill_color[0] = 1.0f;
	br.fill_color[1] = 0.2f;
	br.fill_color[2] = 0.2f;
	br.texture = "";
	br.fill_secondary_color[0] = 1.0f * (1.0f - player_life) + player_life * 0.2f;
	br.fill_secondary_color[1] = 0.2f;
	br.fill_secondary_color[2] = 0.2 * (1.0f - player_life) + player_life * 1.0f;
	br.gradient = true;
	br.gradient_dir_u = 1.0f;
	br.gradient_dir_v = 0.0f;
	graphics::drawRect(CANVAS_WIDTH - 100 - ((1.0f - player_life) * 120 / 2), 30, player_life * 120, 20, br);

	br.outline_opacity = 1.0f;
	br.gradient = false;
	br.fill_opacity = 0.0f;
	graphics::drawRect(CANVAS_WIDTH - 100, 30, 120, 20, br);
	br.fill_opacity = 1.0f;
	
	if (player)
	{
		char info1[40];
		sprintf_s(info1, "score:%3.0f", player->getScore());
		graphics::drawText(20, 30, 50, info1, br);

		char info2[40];
		sprintf_s(info2, "......................");
		graphics::drawText(20, 40, 50, info2, br);
		
		char info3[40];
		sprintf_s(info3, "size:%2.0fX%2.0f", player->getSize(), player->getSize());
		graphics::drawText(20, 70, 50, info3, br);

		br.outline_opacity = 1.0f;
		br.texture = "";
		br.fill_color[0] = 0.3f;
		br.fill_color[1] = 0.3f;
		br.fill_color[2] = 1.0f;
		br.fill_opacity = 0.5f;
		br.gradient = false;
		graphics::drawRect(100,40,185, 80, br);


	}
	
	
	if (player_life <= 0.0f)
	{
		graphics::playSound(std::string(ASSET_PATH) + "lose.wav", 0.01f);
		graphics::Brush br;
		br.texture = ASSET_PATH + std::string("gameover.png");
		br.outline_opacity = 0.0f;
		graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, 200, 200, br);
		
	}
	
	
}


void Game1::update()
{
	if (status == STATUS_START)
	{
		updateStartScreen();
	}
	else
	{
		updateLevelScreen();
	}

	
}

void Game1::draw()
{
	if (status == STATUS_START)
	{
		drawStartScreen();
	}	
	else
	{	
		drawLevelScreen();
	}
}


void Game1::init()
{
	status = STATUS_START;
	graphics::setFont(std::string(ASSET_PATH) + "font1.ttf");

	graphics::playMusic(std::string(ASSET_PATH) + "music1.wav", 0.4f, true, 400);
	
}


Game1::Game1()
{
}

Game1::~Game1()
{
	if (player)
	{
		delete player;
	}
}

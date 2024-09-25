#pragma once
#include "player.h"
#include "enemy.h"
#include "gift.h"
#include "supergift.h"

class Game1 {
	typedef enum {STATUS_START, STATUS_PLAYING}status_t;
	Player *player= nullptr;
	bool player_initialized = false;
	
	Enemy *bomb = nullptr; 
	void spawnBomb();
	void checkBomb();
	bool checkCollision();
	
	Gift* gift = nullptr;
	void spawnGift();
	void checkGift();
	bool checkCollisionGift();

	SuperGift* superGift = nullptr;
	void spawnSuperGift();
	void checkSuperGift();
	bool checkCollisionSuperGift();
	status_t status = STATUS_START ;

	void updateStartScreen();
	void updateLevelScreen();
	void drawStartScreen();
	void drawLevelScreen();
	//void checkLife();
public:
	void update();
	void draw();
	void init();
	Game1();
	~Game1();
};

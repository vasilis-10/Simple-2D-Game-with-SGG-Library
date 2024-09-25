#include "graphics.h"
#include "game1.h"
#include "config.h"

void update(float ms)
{
    Game1 * game = reinterpret_cast<Game1 *>(graphics::getUserData());
    game->update();
}

void draw()
{
    Game1* game = reinterpret_cast<Game1 *>(graphics::getUserData());
    game->draw();
}

int main()
{
    Game1 mygame;
   

    graphics::createWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Game");

    graphics::setUserData(&mygame);

    graphics::setDrawFunction(draw);
    graphics::setUpdateFunction(update);

    graphics::setCanvasSize(CANVAS_WIDTH, CANVAS_HEIGHT);
    graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);
   
    mygame.init();
    graphics::startMessageLoop();
    
    return 0;
}

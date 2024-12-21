#pragma once
#include "game.h"

int main(void)
{
    Game* game = new Game();
 
    game->init();
    
    game->update();


    delete game;
    game = nullptr;

  
    return 0;
}

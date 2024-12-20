#include "game.h"

Game::Game()
{
	player = new Player({100.f, 100.f});
	enemies.push_back(new Enemy(1, 100, {200.f, 200.f}));
	//map = new Map();
}

Game::~Game()
{
	
}

void Game::handleTextures()
{

}

void Game::update()
{
	player->update();
	/*for (auto &e : enemies) {
		e->update();
	}*/
}

void Game::draw() const
{
	player->draw();
	/*for (auto& e : enemies) {
		e->draw();
	}*/
}

void Game::clear()
{

}

//
// EPITECH PROJECT, 2018
// game.cpp
// File description:
// game
//

#include "game.hpp"

Game::Game()
{
	this->map = new Map();
	new Player(this->map, 31);
	this->play();
}

void Game::play()
{
	Interface *interface = new Interface();
	bool nostop = 1;

	this->refresh_map(KEY_NONE, interface);
	std::cout << "FIn du refresh de la map." << std::endl;
	while (interface->getcontext()->device->run() && interface->getcontext()->driver && nostop) {
		if (interface->getcontext()->device->isWindowActive()) {
			std::cout << "Captation des touches" << std::endl;
			nostop = this->refresh_map(interface->getcontext()->input, interface);
			std::cout << "Fin du refresh." << std::endl;
		}
		sleep(1);
	}
	interface->getcontext()->device->drop();
}

bool Game::refresh_map(input_key input, Interface *interface)
{
	std::cout << "Debut du refresh map." << std::endl;
	for (int i = 0; i < MAP_SIZE*MAP_SIZE; i++) {
		for (auto &j : map->get_tile(i).getstack()) {
			if (j->get_type() == PLAYER)
				((Player *)j)->getinput(*map, input);
			if (j->get_type() == BOMBE)
				((Bombe *)j)->update(*map);
			if (j->get_type() == FIRE)
				((Fire *)j)->update(*map);
		}
	}
	std::cout << "Debut de l'affichage de la map." << std::endl;
	if (interface->getcontext()->device->isWindowActive())
		interface->draw_map(this->map);
	std::cout << "Fin de l'affichage de la map." << std::endl;
	return 1;
}
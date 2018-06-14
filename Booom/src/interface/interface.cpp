//
// EPITECH PROJECT, 2018
// game
// File description:
// game
//

#include "interface.hpp"

Interface::Interface()
{
	this->context = new SAppContext();
//	MyEventGame receiver((SAppContext&)this->context);
//	context->device->setEventReceiver(&receiver);
	std::cout << "FIn de la création de l'interface" << std::endl;
}

void Interface::draw_tile(Tile tile, int x, int y)
{
	if (tile.get_type() == WALL) {
		context->guienv->addImage(context->driver->getTexture("files/wall2.png"), irr::core::position2d<int>(x, y));
	}
	if (tile.get_type() == BLOCK) {
		context->guienv->addImage(context->driver->getTexture("files/wall1.png"), irr::core::position2d<int>(x, y));
	}
	if (tile.get_type() == GROUND) {
		context->guienv->addImage(context->driver->getTexture("files/ground.png"), irr::core::position2d<int>(x, y));
	}
	if (tile.get_type() == PLAYER) {
		context->guienv->addImage(context->driver->getTexture("files/bomberman.png"), irr::core::position2d<int>(x, y));
		std::cout << "affiche un player." << std::endl;
	}
	if (tile.get_type() == BOMBE)
		context->guienv->addImage(context->driver->getTexture("files/bombe.png"), irr::core::position2d<int>(x, y));
	if (tile.get_type() == FIRE)
		context->guienv->addImage(context->driver->getTexture("files/explo.png"), irr::core::position2d<int>(x, y));
}

void Interface::draw_map(Map *map)
{
	int x;
	int y;
	int i;
	int j;

	map->display_map_on_console(map);
	for (int i = 0; i < MAP_SIZE; i++) {
		for (int j = 0; j < MAP_SIZE; j++) {
			x = i * SIZE_CASE;
			y = j * SIZE_CASE;
			for (auto &tile : (map->get_tile(i + j * MAP_SIZE)).getstack()) {
				draw_tile(*tile, x, y);
			}
		}
		j = 0;
	}
	std::cout << "FIn de l'affichage de la map" << std::endl;
	this->context->guienv->drawAll();
	this->context->sceneManager->drawAll();
	this->context->driver->endScene();
}

SAppContext* Interface::getcontext()
{
	return this->context;
}
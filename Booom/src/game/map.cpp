//
// EPITECH PROJECT, 2018
// map.cpp
// File description:
// map header
//

#include "map.hpp"

Map::Map(std::string file)
{}

Map::Map() : size(MAP_SIZE)
{
//	std::array<type_of_tile, 36> mapping;
	int i = 0;

	while (i != 36) {
		this->g_map[i] = new Stack();
		i++;
	}
}

void Map::move_tile(Tile *tile, direction dir)
{
	
}

Tile Map::get_tile_dir(Tile *tile, direction dir)
{
	return *tile;
}

void Map::add_tile(Tile *pos, Tile *tile, type_of_tile type)
{

}

void Map::rm_tile(Tile *tile)
{
	
}

void Map::reinit_tile(Tile *pos, Tile *tile, type_of_tile type)
{

}

void Map::display_map_on_console()
{
	int i = 0;

	while (i <= 36) {
		for (size_t j = 0; j < g_map[i]->getstack().size(); j++) {
			printf("%d", (g_map[i]->getstack())[j]->get_type());
			i++;
		}
	}
}

Stack::Stack()
{}

std::vector<Tile*> Stack::getstack() const
{
	return this->stack;
}

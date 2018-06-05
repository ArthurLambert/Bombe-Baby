//
// EPITECH PROJECT, 2018
// map.cpp
// File description:
// map header
//

#include "map.hpp"

Map::Map(std::string file)
{}

Map::Map() : size(MAP_SIZE * MAP_SIZE)
{
	int i = 0;

	while (i != size) {
		this->map[i] = new Stack();
		(this->map[i])->add_to_stack(new Tile(GROUND, i));
		i++;
	}
}

bool Map::move_tile(Tile *tile, direction dir)
{
	Stack next_tile;

	next_tile = (this->get_tile_dir(tile, dir));
	for (auto &i : next_tile.getstack()) {
		if (i->get_type() != GROUND)
			return false;
	}
	this->rm_tile(tile);
	tile->set_pos(this->get_next_pos(tile->get_pos(), dir));
	this->add_tile(tile);
	return true;
}

Stack Map::get_tile_dir(Tile *tile, direction dir)
{
	return *map[get_next_pos(tile->get_pos(), dir)];
}

void Map::add_tile(Tile *tile)
{
	this->map[tile->get_pos()]->add_to_stack(tile);
}

void Map::rm_tile(Tile *tile)
{
	this->map[tile->get_pos()]->rm_from_stack(tile);
}

void Map::reinit_tile(Tile *tile)
{
	this->map[tile->get_pos()]->clear_stack();
	this->add_tile(tile);
}

int Map::get_next_pos(int pos, direction dir)
{
	if (dir == UP)
		return (pos - MAP_SIZE);
	else if (dir == DOWN)
		return (pos + MAP_SIZE);
	else if (dir == LEFT)
		return (pos - 1);
	else if (dir == RIGHT)
		return (pos + 1);
	return pos;
}

void Map::display_map_on_console()
{
	int i = 0;
	int j = 0;

	for (i = 0; i < MAP_SIZE; i++) {
		for (j = 0; j < MAP_SIZE; j++) {
			printf("%d", (this->map[i + j * MAP_SIZE]->getstack())[0]->get_type());
		}
		j = 0;
		printf("\n");
	}
}

Stack::Stack()
{}

std::vector<Tile*> Stack::getstack() const
{
	return this->stack;
}

void Stack::add_to_stack(Tile *tile)
{
	this->stack.push_back(tile);
}

bool Stack::rm_from_stack(Tile *tile)
{
	for (unsigned int i = 0; i < stack.size(); i++) {
		if (tile == stack[i]) {
			stack.erase(stack.begin() + i);
			return true;
		}
	}
	return false;
}

void Stack::clear_stack()
{
	this->stack.clear();
}

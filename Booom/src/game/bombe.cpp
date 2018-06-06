//
// EPITECH PROJECT, 2018
// bombe.cpp
// File description:
// bombe member function
//

#include "bombe.hpp"

Fire::Fire(Map map, int pos, int power, direction dir) : Tile(FIRE, pos), duration(power), dir(dir)
{
	map.add_tile(this);
}

void Fire::extinct(Map map)
{
	if (this->duration == 0) {
		map.rm_tile(this);
		this->~Fire();
	}
	else
		this->duration--;
}

Bombe::Bombe(int pos, Map map, int power) : Tile(BOMBE, pos), tictac(300), power(power)
{
	map.add_tile(this);
}

void Bombe::explode(Map map)
{
	Bonus *bonus;
	if (this->power > 0) {
		this->spread(map, UP);
		this->spread(map, DOWN);
		this->spread(map, RIGHT);
		this->spread(map, LEFT);
		this->power--;
	}
	else {
		bonus = new Bonus(this->get_pos());
		map.add_tile(bonus);
		map.rm_tile(this);
		this->~Bombe();
	}
}

void Bombe::tic(Map map)
{
	if (tictac == 0)
		this->explode(map);
	else
		this->tictac--;
}

void Bombe::spread(Map map, direction dir)
{
	Fire *fire;
	int pos = this->get_pos();

	while (this->is_fire(map.get_tile_dir(pos, dir))) {
		pos = map.get_next_pos(pos, dir);
	}
	if (this->can_start_fire(map.get_tile_dir(pos, dir))) {
		fire = new Fire(map, this->get_pos(), this->power, dir);
	}
	else if (this->power == 1) {
		this->try_destroy(map, map.get_tile_dir(pos, dir));	
	}
}

bool Bombe::is_fire(Stack stack)
{
	for (auto &i : stack.getstack()) {
		if (i->get_type() == FIRE)
			return true;
	}
	return false;
}

bool Bombe::can_start_fire(Stack stack)
{
	for (auto &i : stack.getstack()) {
		if (i->get_type() == WALL || i->get_type() == BLOCK)
			return false;
	}
	return true;
}

void Bombe::try_destroy(Map map, Stack stack)
{
	for (auto &i : stack.getstack()) {
		if (i->get_type() == BLOCK) {
			((Block*)i)->destroy_block(map);
		}
	}
}

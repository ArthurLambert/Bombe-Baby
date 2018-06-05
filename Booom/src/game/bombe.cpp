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
	//?
}

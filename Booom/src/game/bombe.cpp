//
// EPITECH PROJECT, 2018
// bombe.cpp
// File description:
// bombe member function
//

#include "bombe.hpp"

Fire::Fire(Map map, Tile *pos, int power, direction dir) : Tile(FIRE), duration(power), dir(dir)
{
	map.add_tile(pos, this, FIRE);
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

Bombe::Bombe(Player *player, Map map) : Tile(BOMBE), tictac(300)
{
	map.add_tile(player, this, BOMBE);
}

void Bombe::explode(Map map)
{
	if (this->power > 0) {
		this->spread(map, UP);
		this->spread(map, DOWN);
		this->spread(map, RIGHT);
		this->spread(map, LEFT);
		this->power--;
	}
	else {
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
	Fire *fire = new Fire(map, this, this->power, dir);

	while ((map.get_tile_dir(this, dir)).get_type() == FIRE) {
		map.move_tile(fire, dir);
	}
	if ((map.get_tile_dir(this, dir)).get_type() == GROUND) {
		map.move_tile(fire, dir);
	}
	//?
}

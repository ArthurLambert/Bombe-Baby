//
// EPITECH PROJECT, 2018
// bombe.hpp
// File description:
// bombe header
//

#ifndef BOMBE_HPP_
#define BOMBE_HPP_

#include "map.hpp"
#include "player.hpp"
#include "tile.hpp"

class Bombe : public Tile
{
public:
	Bombe(Player *player, Map map);
	~Bombe() = default;
	void explode(Map map);
	void tic(Map map);
	void spread(Map map, direction dir);

private:
	int tictac;
	int power;
};

class Fire : public Tile
{
public:
	Fire(Map map, Tile *pos, int power, direction dir);
	~Fire() = default;
	void extinct(Map map);

private:
	int duration;
	direction dir;
};

#endif

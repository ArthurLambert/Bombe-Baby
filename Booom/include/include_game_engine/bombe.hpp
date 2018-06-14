//
// EPITECH PROJECT, 2018
// bombe.hpp
// File description:
// bombe header
//

#ifndef BOMBE_HPP_
#define BOMBE_HPP_

#include "map.hpp"
#include "tile.hpp"
#include "bonus.hpp"
#include "block.hpp"

class Bombe : public Tile
{
public:
	Bombe(int pos, Map map, int power);
	~Bombe() = default;
	void explode(Map map);
	void tic(Map map);
	void spread(Map map, direction dir);
	bool is_fire(Stack stack);
	bool can_start_fire(Stack stack);
	void try_destroy(Map map, Stack stack);
	void update(Map &map);

private:
	int tictac;
	int power;
};

class Fire : public Tile
{
public:
	Fire(Map map, int pos, int power, direction dir);
	~Fire() = default;
	void extinct(Map map);
	void update(Map &map);

private:
	int duration;
	direction dir;
};

#endif

//
// EPITECH PROJECT, 2018
// bombe.hpp
// File description:
// bombe header
//

#ifndef BOMBE_HPP_
#define BOMBE_HPP_

#include "map.hpp"

class Bombe : public Tile
{
public:
	Bombe(Map map);
	~Bombe() = default;
	void explode(Map map);
	void tic();

private:
	int tictac;
	int power;
};

class Fire : public Tile
{
public:
	Fire();
	~Fire();
};

#endif

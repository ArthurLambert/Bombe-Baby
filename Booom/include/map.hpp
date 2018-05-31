//
// EPITECH PROJECT, 2018
// map.hpp
// File description:
// map header
//

#ifndef MAP_HPP_
#define MAP_HPP_

#include "game.hpp"

class Map
{
public:
	Map(char* file);
	Map(); //test
	~Map() = default;
	void move_tile(Tile tile, direction dir);
	void create(Tile tile, type_of_tile type);

private:
 vector< vector<Tile*> > map;
	int size;
};

#endif

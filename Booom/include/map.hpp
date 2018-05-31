//
// EPITECH PROJECT, 2018
// map.hpp
// File description:
// map header
//

#ifndef MAP_HPP_
#define MAP_HPP_

#include "game.hpp"

#define MAP_SIZE 15*15

class Map
{
public:
	Map(char* file);
	Map(); //test
	~Map() = default;
	void move_tile(Tile tile, direction dir);
	Tile get_tile_dir(Tile tile, direction dir);
	void add_tile(Tile tile, type_of_tile type, Position pos);
	void create_tile(Tile tile, type_of_tile type, Position pos);

private:
 vector< vector<Tile*> > map;
	int size;
};

class Position
{
public:
	Position();
	~Position() = default;

private:
	int x;
	int y;
};

#endif

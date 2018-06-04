//
// EPITECH PROJECT, 2018
// map.hpp
// File description:
// map header
//

#ifndef MAP_HPP_
#define MAP_HPP_

#include "tile.hpp"
#include <array>
#include <vector>

#define MAP_SIZE 6 //the map is a square, give the length of a side

class Stack
{
public:
	Stack();
	~Stack() = default;
	std::vector<Tile*> getstack() const;

private:
	std::vector<Tile*> stack;
};

class Map
{
public:
	Map(std::string file);
	Map(); //test
	~Map() = default;
	void move_tile(Tile *tile, direction dir);
	Tile get_tile_dir(Tile *tile, direction dir);
	void add_tile(Tile *pos, Tile *tile, type_of_tile type);
	void rm_tile(Tile *tile);
	void reinit_tile(Tile *pos, Tile *tile, type_of_tile type);
	
	//display for test only
	void display_map_on_console();

private:
	std::array<Stack*, 36> g_map; //second parrameter of the array is always MAP_SIZE^2
	int size;
};

/*
class Position
{
public:
	Position();
	~Position() = default;

private:
	int x;
	int y;
};
*/
#endif

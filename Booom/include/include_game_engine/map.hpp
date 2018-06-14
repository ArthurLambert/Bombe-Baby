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

#define MAP_SIZE 29 //the map is a square, give the length of a side

class Stack
{
public:
	Stack();
	~Stack() = default;
	std::vector<Tile*> getstack() const;
	void add_to_stack(Tile *tile);
	bool rm_from_stack(Tile *tile);
	void clear_stack();

private:
	std::vector<Tile*> stack;
};

class Map
{
public:
	Map(std::string file);
	Map(); //test
	~Map() = default;
	bool move_tile(Tile *tile, direction dir);
	Stack get_tile_dir(int pos, direction dir);
	Stack get_tile(int pos);
	void add_tile(Tile *tile);
	void rm_tile(Tile *tile);
	void reinit_tile(Tile *tile);
	int get_next_pos(int pos, direction dir);
	
	//display for test only
	void display_map_on_console(Map *map);

private:
	std::array<Stack*, 29*29> map; //second parrameter of the array is always MAP_SIZE^2
	int size;
};

#endif

//
// EPITECH PROJECT, 2018
// game.hpp
// File description:
// game header
//

#ifndef GAME_HPP_
#define GAME_HPP_

#include "main.hpp"
#include <vector>

//#define MAP_SIZE 17*17

class Game
{
public:
	Game();
	~Game() = default;
	void play();	
	void refresh_map(Map map);

private:
	Map map;
};

enum type_of_tile
{
	BLOCK,
	WALL,
	PLAYER,
	BOMBE,
	GROUDE
};

enum bonus_type
{
	SPEED,
	SEED,
	WEED
};

enum direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

class Tile
{
public:
	Tile(type_of_tile type);
	~Tile() = default;
	type_of_tile get_type() const;

private:
	type_of_tile type;
};

#endif

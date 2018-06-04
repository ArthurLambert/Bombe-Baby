//
// EPITECH PROJECT, 2018
// tile.hpp
// File description:
// tile header
//

#ifndef TILE_HPP_
#define TILE_HPP_

enum type_of_tile
{
	BLOCK,
	WALL,
	PLAYER,
	BOMBE,
	GROUND,
	BONUS,
	FIRE
};

enum bonus_type
{
	SPEED,
	SEED,
	WEED,
	NONE
};

enum direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	STAY,
	ALL
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

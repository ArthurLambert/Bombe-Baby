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
	FIRE,
	VOID
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
	Tile(type_of_tile type, int pos);
	~Tile() = default;
	type_of_tile get_type() const;
	int get_pos() const;
	void set_pos(int pos);

private:
	type_of_tile type;
	int pos;
};

#endif

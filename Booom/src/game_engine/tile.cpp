//
// EPITECH PROJECT, 2018
// tile.cpp
// File description:
// tile function
//

#include "tile.hpp"

Tile::Tile(type_of_tile type, int pos) : type(type), pos(pos) 
{}

type_of_tile Tile::get_type() const
{
	return this->type;
}

int Tile::get_pos() const
{
	return this->pos;
}

void Tile::set_pos(int pos)
{
	this->pos = pos;
}

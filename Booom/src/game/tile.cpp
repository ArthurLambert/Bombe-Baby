//
// EPITECH PROJECT, 2018
// tile.cpp
// File description:
// tile function
//

#include "tile.hpp"

Tile::Tile(type_of_tile type) : type(type)
{}

type_of_tile Tile::get_type() const
{
	return this->type;
}

//
// EPITECH PROJECT, 2018
// block.hpp
// File description:
// block header
//

#ifndef BLOCK_HPP_
#define BLOCK_HPP_

#include "map.hpp"

class Block : public Tile
{
public :
	Block();
	~Block(Map map);
	~Block() = default;

private:
};

#endif

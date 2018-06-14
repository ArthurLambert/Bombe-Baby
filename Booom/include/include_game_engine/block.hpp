//
// EPITECH PROJECT, 2018
// block.hpp
// File description:
// block header
//

#ifndef BLOCK_HPP_
#define BLOCK_HPP_

#include "bonus.hpp"
#include "tile.hpp"
#include "map.hpp"

class Block : public Tile
{
public :
	Block(int pos);
	~Block() = default;
	void destroy_block(Map map);

private:
};

#endif

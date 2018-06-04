//
// EPITECH PROJECT, 2018
// game.hpp
// File description:
// game header
//

#ifndef GAME_HPP_
#define GAME_HPP_

#include "map.hpp"

class Game
{
public:
	Game();
	~Game() = default;
	void play();	
	void refresh_map();

private:
	Map map;
};

#endif

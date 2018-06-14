//
// EPITECH PROJECT, 2018
// player.hpp
// File description:
// player header
//

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "map.hpp"
#include "bonus.hpp"
#include "interface.hpp"

class Player : public Tile
{
public:
	Player(Map* map, int pos);
	~Player() = default;
	void move(direction dir, Map map);
	void get_hit(Map map);
	void pick_bonus(Bonus *bonus , Map map);
	int getpv() const;
	std::vector<char> getname() const;
	void drop_bombe(Map map);
	void getinput(Map &map, input_key input);

private:
	int pv;
	int nb_bombe;
	int speed;
	int power;
	int config[5];
};

#endif
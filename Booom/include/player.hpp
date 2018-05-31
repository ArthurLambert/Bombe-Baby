//
// EPITECH PROJECT, 2018
// player.hpp
// File description:
// player header
//

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "map.hpp"

class Player : public Tile
{
public:
	Player(vector<char> name, Map map);
	~Player() = default;
	void move(direction dir, Map map);
	void get_hit(Map map);
	void pick_bonus(Block bonus, Map map);
	int getpv() const;
	vector<char> getname() const;
	void drop_bombe(Map map);
	direction getimput();

private:
	int pv;
	vector<char> name;
	int nb_bombe;
	int speed;
	int power;
	int config[5];
};

#endif

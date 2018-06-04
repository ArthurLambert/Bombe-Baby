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

class Player : public Tile
{
public:
	Player(std::vector<char> name, Map map);
	~Player() = default;
	void move(direction dir, Map map);
	void get_hit(Map map);
	void pick_bonus(Bonus bonus , Map map);
	int getpv() const;
	std::vector<char> getname() const;
	void drop_bombe(Map map);
	direction getimput();

private:
	int pv;
	std::vector<char> name;
	int nb_bombe;
	int speed;
	int power;
	int config[5];
};

#endif

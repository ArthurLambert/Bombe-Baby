//
// EPITECH PROJECT, 2018
// bonus.hpp
// File description:
// bonus header
//

#ifndef BONUS_HPP_
#define BONUS_HPP_

class Bonus : public Tile
{
public:
	Bonus();
	~Bonus() = default;

private:
	bonus_type bonus;
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:47:02 by sna               #+#    #+#             */
/*   Updated: 2022/04/03 14:40:09 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("default"), _hit(10), _energy(10), _attack(0)
{
	std::cout << GREEN;
	std::cout << "ClapTrap default constructor called : [ " << _name << " ]" << std::endl;
	std::cout << RESET;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit(10), _energy(10), _attack(0)
{
	std::cout << GREEN;
	std::cout << "ClapTrap string constructor called : [ " << _name << " ]" << std::endl;
	std::cout << RESET;
}

ClapTrap::ClapTrap(const ClapTrap& obj) : _name(obj._name), _hit(obj._hit), _energy(obj._energy), _attack(obj._attack)
{
	std::cout << GREEN;
	std::cout << "ClapTrap copy constructor called : [ " << _name << " ]" << std::endl;
	std::cout << RESET;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << RED;
	std::cout << "ClapTrap destructor called : [ " << _name << " ]" << std::endl;
	std::cout << RESET;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& obj)
{
	_name = obj._name;
	_hit = obj._hit;
	_energy = obj._energy;
	_attack = obj._attack;
	std::cout << PURPLE;
	std::cout << "ClapTrap operator = called : [ " << _name << " ]" << std::endl;
	std::cout << RESET;
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	std::cout << YELLOW;
	if (_hit <= 0)
	{
		std::cout << "ClapTrap [ " << _name << " ] already dead." << std::endl;
		std::cout << RESET;
		return ;
	}
	else if (_energy <= 0)
	{
		std::cout << "ClapTrap [ " << _name << " ] has no energy." << std::endl;
		std::cout << RESET;
		return ;
	}
	else
	{
		std::cout << "ClapTrap [ " << _name << " ] attacks [ " << target << " ], causing " << _attack << " points of damage!" << std::endl;
		_energy--;
		std::cout << "ClapTrap [ " << _name << " ] remain energy : " << _energy << std::endl;
	}

	std::cout << RESET;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << YELLOW;
	if (_hit <= 0)
	{
		std::cout << "Claptrap [ " << _name << " ] not damaged : (Already dead)" << std::endl;
		std::cout << RESET;
		return ;
	}
	std::cout << "ClapTrap [ " << _name << " ] has taken damage with an " << amount << " point!" << std::endl;
	_hit -= amount;
	if (_hit <= 0)
	{
		_hit = 0;
		std::cout << "ClapTrap [ " << _name << " ] died" << std::endl;
	}
	else
		std::cout << "ClapTrap [ " << _name << " ] a remain hitPoint : " << _hit << std::endl;
	std::cout << RESET;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << YELLOW;
	if (_hit <= 0)
	{
		std::cout << "ClapTrap : [ " << _name << " ] not repaired : (Already dead)" << std::endl;
		std::cout << RESET;
		return ;
	}
	if (_energy <= 0)
	{
		std::cout << "ClapTrap : [ " << _name << " ] not repaired : (No energy)" << std::endl;
		std::cout << RESET;
		return ;
	}
	_hit += amount;
	if (_hit > 10)
		_hit = 10;
	std::cout << "ClapTrap [ " << _name << " ] has been repaired an " << amount << " point!" << std::endl;
	std::cout << "ClapTrap [ " << _name << " ] a remain hitPoint : " << _hit << std::endl;
	_energy--;
	std::cout << "ClapTrap [ " << _name << " ] remain energy : " << _energy << std::endl;
	std::cout << RESET;
}

unsigned int	ClapTrap::getAttack(void) const
{
	return (_attack);
}
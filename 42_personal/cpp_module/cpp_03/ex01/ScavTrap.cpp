/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 15:25:57 by sna               #+#    #+#             */
/*   Updated: 2022/04/02 16:13:03 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap(), _guardMode(false)
{
	_hit = 100;
	_energy = 50;
	_attack = 20;
	std::cout << GREEN;
	std::cout << "ScavTrap default constructor called. : [ " << _name << " ]" << std::endl;
	std::cout << RESET; 
}

ScavTrap::ScavTrap(const std::string name): ClapTrap(name), _guardMode(false)
{
	_hit = 100;
	_energy = 50;
	_attack = 20;
	std::cout << GREEN;
	std::cout << "ScavTrap string constructor called. : [ " << _name << " ]" << std::endl;
	std::cout << RESET; 
}

ScavTrap::ScavTrap(const ScavTrap& obj): ClapTrap(obj), _guardMode(obj._guardMode)
{
	std::cout << GREEN;
	std::cout << "ScavTrap copy constructor called. : [ " << _name << " ]" << std::endl;
	std::cout << RESET; 
}

ScavTrap::~ScavTrap()
{
	std::cout << RED;
	std::cout << "ScavTrap destructor called. : [ " << _name << " ]" << std::endl;
	std::cout << RESET;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& obj)
{
	ClapTrap::operator=(obj);
	_guardMode = obj._guardMode;
	std::cout << PURPLE;
	std::cout << "ScavTrap operator= called. : [ " << _name << " ]" << std::endl;
	std::cout << RESET;
	return (*this);
}

void	ScavTrap::attack(const std::string& target)
{
	std::cout << YELLOW;
	if (_hit <= 0)
	{
		std::cout << "ScavTrap [ " << _name << " ] already dead." << std::endl;
		std::cout << RESET;
		return ;
	}
	if (_energy <= 0)
	{
		std::cout << "ScavTrap [ " << _name << " ] has no energy." << std::endl;
		std::cout << RESET;
	}
	else
	{
		std::cout << "ScavTrap [ " << _name << " ] attacks [ " << target << " ], causing " << _attack << " points of damage!" << std::endl;
		_energy--;
		std::cout << "ScavTrap [ " << _name << " ] remain energy : " << _energy << std::endl;
	}
	std::cout << RESET;
}

void	ScavTrap::guardGate(void)
{
	std::cout << YELLOW;
	if (_hit)
	{
		std::cout << "ScavTrap [ " << _name << " ] switch to guard mode." << std::endl;
		_guardMode = true;
	}
	else
		std::cout << "ScavTrap [ " << _name << " ] already dead." << std::endl;
	std::cout << RESET; 
}
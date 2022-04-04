/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 18:31:24 by sna               #+#    #+#             */
/*   Updated: 2022/04/04 15:06:28 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void): _name(ClapTrap::_name)
{
	ClapTrap::_name += "_clap_name";
	_hit = FragTrap::_hit;//100
	_energy = ScavTrap::_energy;//50
	_attack = FragTrap::_attack;//30
	std::cout << GREEN;
	std::cout << "DiamondTrap default constructor called. : [ " << _name << " ]" << std::endl;
	std::cout << RESET; 
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name), FragTrap(name), ScavTrap(name), _name(name)
{
	ClapTrap::_name += "_clap_name";
    _hit = FragTrap::_hit;//100
    _energy = ScavTrap::_energy;//50
    _attack = FragTrap::_attack;//30
    std::cout << GREEN;
	std::cout << "DiamondTrap string constructor called. : [ " << _name << " ]" << std::endl;
	std::cout << RESET; 
}

DiamondTrap::DiamondTrap(const DiamondTrap& obj): ClapTrap(obj), FragTrap(obj), ScavTrap(obj), _name(obj._name)
{
	std::cout << GREEN;
	std::cout << "DiamondTrap copy constructor called. : [ " << _name << " ]" << std::endl;
	std::cout << RESET; 
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << RED;
	std::cout << "DiamondTrap destructor called. : [ " << _name << " ]" << std::endl;
	std::cout << RESET;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& obj)
{
	ClapTrap::operator=(obj);
	_name = obj._name;
	std::cout << PURPLE;
	std::cout << "DiamondTrap operator= called. : [ " << _name << " ]" << std::endl;
	std::cout << RESET;
	return (*this);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << YELLOW;
	std::cout << "DiamondTrap name : [ " << _name << " ] and ClapTrap name : [ " << ClapTrap::_name << " ]" << std::endl;
	std::cout << RESET;
}
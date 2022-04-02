/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 17:06:45 by sna               #+#    #+#             */
/*   Updated: 2022/04/02 17:33:42 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap()
{
	_hit = 100;
    _energy = 100;
    _attack = 30;
    std::cout << GREEN;
	std::cout << "FragTrap default constructor called. : [ " << _name << " ]" << std::endl;
	std::cout << RESET; 
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	_hit = 100;
    _energy = 100;
    _attack = 30;
    std::cout << GREEN;
	std::cout << "FragTrap string constructor called. : [ " << _name << " ]" << std::endl;
	std::cout << RESET; 
}

FragTrap::FragTrap(const FragTrap& obj): ClapTrap(obj)
{
    std::cout << GREEN;
	std::cout << "FragTrap copy constructor called. : [ " << _name << " ]" << std::endl;
	std::cout << RESET; 
}

FragTrap::~FragTrap(void)
{
    std::cout << RED;
	std::cout << "FragTrap destructor called. : [ " << _name << " ]" << std::endl;
	std::cout << RESET;
}

FragTrap& FragTrap::operator=(const FragTrap& obj)
{
    ClapTrap::operator=(obj);
    std::cout << PURPLE;
	std::cout << "FragTrap operator= called. : [ " << _name << " ]" << std::endl;
	std::cout << RESET;
    return (*this);
}

void    FragTrap::highFivesGuys(void)
{
    std::cout << YELLOW;
    std::cout << "FragTrap [ " << _name << " ] positive high fives request." << std::endl;
    std::cout << RESET;
}
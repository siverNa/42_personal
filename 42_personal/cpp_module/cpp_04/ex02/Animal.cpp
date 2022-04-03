/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 15:15:08 by sna               #+#    #+#             */
/*   Updated: 2022/04/03 20:51:07 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void): _type("Animal")
{
	std::cout << "Animal default constructor called." << std::endl;
}

Animal::Animal(const Animal& obj): _type(obj.getType())
{
	std::cout << "Animal copy constructor called." << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called." << std::endl;
}

Animal& Animal::operator=(const Animal& obj)
{
	_type = obj.getType();
	std::cout << "Animal operator= called." << std::endl;
	return (*this);
}

std::string Animal::getType(void) const
{
	return (_type);
}
void Animal::setType(const std::string& type)
{
	_type = type;
}
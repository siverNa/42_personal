/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 17:02:03 by sna               #+#    #+#             */
/*   Updated: 2022/04/03 17:13:14 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void): _type("WrongAnimal")
{
	std::cout << "WrongAnimal default constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& obj): _type(obj.getType())
{
	std::cout << "WrongAnimal copy constructor called." << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor called." << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& obj)
{
	_type = obj.getType();
	std::cout << "WrongAnimal operator= called." << std::endl;
	return (*this);
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "(not setting sound)" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return (_type);
}

void		WrongAnimal::setType(const std::string& type)
{
	_type = type;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 17:14:14 by sna               #+#    #+#             */
/*   Updated: 2022/04/03 17:23:29 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void): WrongAnimal()
{
	_type = "WrongCat";
	std::cout << "WrongCat default constructor called." << std::endl;
}

WrongCat::WrongCat(const WrongCat& obj): WrongAnimal()
{
	_type = obj.getType();
	std::cout << "WrongCat copy constructor called." << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called." << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& obj)
{
	_type = obj.getType();
	std::cout << "WrongCat operator= called." << std::endl;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Meow Meow" << std::endl;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 16:09:31 by sna               #+#    #+#             */
/*   Updated: 2022/04/03 17:21:45 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void): Animal()
{
	_type = "Cat";
	std::cout << "Cat default constructor called." << std::endl;
}

Cat::Cat(const Cat& obj): Animal()
{
	_type = obj.getType();
	std::cout << "Cat copy constructor called." << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called." << std::endl;
}

Cat& Cat::operator=(const Cat& obj)
{
	_type = obj.getType();
	std::cout << "Cat operator= called." << std::endl;
	return (*this);
}

void    Cat::makeSound(void) const
{
	std::cout << "Meow Meow" << std::endl;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 16:01:17 by sna               #+#    #+#             */
/*   Updated: 2022/04/03 16:52:30 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void): Animal()
{
	_type = "Dog";
	std::cout << "Dog default constructor called." << std::endl;
}

Dog::Dog(const Dog& obj): Animal()
{
	_type = obj.getType();
	std::cout << "Dog copy constructor called." << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called." << std::endl;
}

Dog& Dog::operator=(const Dog& obj)
{
	_type = obj.getType();
	std::cout << "Dog operator= called." << std::endl;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Bowwow Bowwow" << std::endl;
}
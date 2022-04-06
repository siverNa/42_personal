/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 16:01:17 by sna               #+#    #+#             */
/*   Updated: 2022/04/06 15:47:10 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void): Animal()
{
	_type = "Dog";
	_brain = new Brain();
	std::cout << "Dog default constructor called." << std::endl;
}

Dog::Dog(const Dog& obj): Animal()
{
	_type = obj.getType();
	_brain = new Brain();
	for (int i = 0; i < 100; i++)
		_brain->getIdea(i) = obj._brain->getIdea(i);
	std::cout << "Dog copy constructor called." << std::endl;
}

Dog::~Dog(void)
{
	delete _brain;
	std::cout << "Dog destructor called." << std::endl;
}

Dog& Dog::operator=(const Dog& obj)
{
	_type = obj.getType();
	for (int i = 0; i < 100; i++)
		_brain->getIdea(i) = obj._brain->getIdea(i);
	std::cout << "Dog operator= called." << std::endl;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Bowwow Bowwow" << std::endl;
}

Brain	*Dog::getBrain(void) const
{
	if (_brain)
		return (_brain);
	return (NULL);
}
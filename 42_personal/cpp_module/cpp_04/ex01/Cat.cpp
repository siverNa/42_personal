/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 16:09:31 by sna               #+#    #+#             */
/*   Updated: 2022/04/03 19:56:10 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void): Animal()
{
	_type = "Cat";
	_brain = new Brain();
	std::cout << "Cat default constructor called." << std::endl;
}

Cat::Cat(const Cat& obj): Animal()
{
	_type = obj.getType();
	_brain = new Brain();
	for (int i = 0; i < 100; i++)
		_brain->_idea[i] = obj._brain->_idea[i];
	std::cout << "Cat copy constructor called." << std::endl;
}

Cat::~Cat(void)
{
	delete _brain;
	std::cout << "Cat destructor called." << std::endl;
}

Cat& Cat::operator=(const Cat& obj)
{
	_type = obj.getType();
	for (int i = 0; i < 100; i++)
		_brain->_idea[i] = obj._brain->_idea[i];
	std::cout << "Cat operator= called." << std::endl;
	return (*this);
}

void    Cat::makeSound(void) const
{
	std::cout << "Meow Meow" << std::endl;
}

Brain	*Cat::getBrain(void) const
{
	if (_brain)
		return (_brain);
	return (NULL);
}
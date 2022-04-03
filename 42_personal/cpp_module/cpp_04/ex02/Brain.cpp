/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 18:10:31 by sna               #+#    #+#             */
/*   Updated: 2022/04/03 20:04:49 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	for (int i = 0; i < 100; i++)
		_idea[i] = "idea";
	std::cout << "Brain default constructor called." << std::endl;
}

Brain::Brain(const Brain& obj)
{
	for (int i = 0; i < 100; i++)
		_idea[i] = obj.getIdea(i);
	std::cout << "Brain copy constructor called." << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called." << std::endl;
}

Brain& Brain::operator=(const Brain& obj)
{
	for (int i = 0; i < 100; i++)
		_idea[i] = obj.getIdea(i);
	std::cout << "Brain operator= called." << std::endl;
	return (*this);
}

std::string Brain::getIdea(const int& i) const
{
	return (_idea[i]);
}

void		Brain::setIdea(const int& i, const std::string& idea)
{
	_idea[i] = idea;
}
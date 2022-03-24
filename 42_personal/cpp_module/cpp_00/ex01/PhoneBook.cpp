/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:26:16 by sna               #+#    #+#             */
/*   Updated: 2022/03/24 22:39:39 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->_count = 0;
}
PhoneBook::~PhoneBook()
{
}

void PhoneBook::show_main(void)
{
	std::cout << "@ PhoneBook Service!" << std::endl;
	std::cout << "@ enter your command : ADD | SEARCH | EXIT " << std::endl;
}

void PhoneBook::add_contact(void)
{
	if (this->_count == 8)
		std::cout << "@ PhoneBook is full up to number 8!" << std::endl;
	else if (this->_contact[this->_count].set_information(this->_count + 1))
		this->_count++;
}

void PhoneBook::search_contact(void)
{
	int		index;

	if (this->_count == 0)
		std::cout << "@ First, you should enter contact befor SEARCH!" << std::endl;
	else
	{
		this->show_search_info();
		std::cout << "@ Please enter the index you want to find. add 0 is exit\n";
		while (!(std::cin >> index) || (index < 0 || index > this->_count))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "@ You enter invalid index!" << std::endl;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (index > 0)
			this->_contact[index - 1].display();
	}
}

void PhoneBook::show_search_info(void)
{
	std::cout << "     Index|First name| Last name| Nickname" << std::endl;
	for (int i = 0; i < this->_count; i++)
		this->_contact[i].display_info();
	std::cout << "---------------------------------------------" << std::endl;
}

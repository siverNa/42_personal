/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:55:23 by sna               #+#    #+#             */
/*   Updated: 2022/03/25 00:51:25 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	this->_index = 0;
	for (int i = 0; i < 5; i++)
		this->_information[i] = std::string();
}

Contact::~Contact()
{
}

std::string Contact::_field_names[5] = {
	"first name",
	"last name",
	"nickname",
	"phone number",
	"darkest secret"
};

bool Contact::set_information(int index)
{
	this->_index = index;
	for (int i = 0; i < 5; i++)
	{
		std::cout << "@ " << Contact::_field_names[i] << ":\n";
		std::getline(std::cin, this->_information[i]);
	}

	size_t str_len = 0;
	for (int i = 0; i < 5; i++)
		str_len = str_len + this->_information[i].length();
	if (str_len == 0)
	{
		std::cout << "@ Ouch! You can't enter an empty contact!" << std::endl;
		return (false);
	}
	std::cout << "@ Successfully put in contact!" << std::endl;
	return (true);
}

void Contact::display_info(void)
{
	std::cout << "|" << std::setw(10) << this->_index;
	for (int i = 0; i < 3; i++)
	{
		std::cout << "|";
		if (this->_information[i].length() > 10)
			std::cout << this->_information[i].substr(0, 9) << ".";
		else
			std::cout << std::setw(10) << this->_information[i];
	}
	std::cout << "|" << std::endl;
}

void Contact::display(void)
{
	std::cout << "@ Contact " << this->_index << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << Contact::_field_names[i] << ": ";
		std::cout << this->_information[i] << std::endl;
	}
}
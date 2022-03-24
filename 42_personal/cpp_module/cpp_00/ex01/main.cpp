/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 01:16:56 by sna               #+#    #+#             */
/*   Updated: 2022/03/24 22:34:19 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook	phonebook;
	std::string	command;
	bool		status;

	phonebook.show_main();
	status = true;
	while (status)
	{
		std::cout << "input > ";
		std::getline(std::cin, command);
		if (command == "ADD")
			phonebook.add_contact();
		else if (command == "SEARCH")
			phonebook.search_contact();
		else if (command == "EXIT")
		{
			std::cout << "@ you input EXIT. goodbye!" << std::endl;
			status = false;
		}
		else
			std::cout << "@ You have entered a command that is not on the list." << std::endl;
	}
	return (0);
}
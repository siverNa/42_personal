/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 00:18:10 by sna               #+#    #+#             */
/*   Updated: 2022/03/30 15:10:04 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	init();
}

Harl::~Harl(void)
{
}

void	Harl::complain(std::string level)
{
	for (int i = 0; i < 4; i++)
	{
		if (lookup[i].str == level)
			(this->*(lookup[i].f))();
	}
}

void	Harl::init(void)
{
	lookup[0].str = "DEBUG";
	lookup[0].f = &Harl::debug;
	lookup[1].str = "INFO";
	lookup[1].f = &Harl::info;
	lookup[2].str = "WARNING";
	lookup[2].f = &Harl::warning;
	lookup[3].str = "ERROR";
	lookup[3].f = &Harl::error;
}

void	Harl::debug()
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon "
	<< "for my 7XL-double-cheese-triple-pickle-specialketchup burger."
	<< std::endl << "I really do!"
	<< std::endl << std::endl;
}

void	Harl::info()
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money."
	<< std::endl << "You didn’t put enough bacon in my burger!"
	<< std::endl << "If you did, I wouldn’t be asking for more!"
	<< std::endl << std::endl;
}

void	Harl::warning()
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free."
	<< std::endl << "I’ve been coming for years whereas you started working here since last month."
	<< std::endl << std::endl;;
}

void	Harl::error()
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl;
}
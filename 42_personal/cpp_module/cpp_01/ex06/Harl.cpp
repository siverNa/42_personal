/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 23:50:26 by sna               #+#    #+#             */
/*   Updated: 2022/03/30 00:52:16 by sna              ###   ########.fr       */
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
	int status;

	status = 0;
	for (int i = 1; i < 5; i++)
		if (lookup[i].str == level)
			status = i;

	switch (status)
	{
		case 0:
			(this->*(lookup[0].f))();
			break;
		case 1:
			(this->*(lookup[1].f))();
		case 2:
			(this->*(lookup[2].f))();
		case 3:
			(this->*(lookup[3].f))();
		case 4:
			(this->*(lookup[4].f))();
			break;
	}
}

void	Harl::init(void)
{
	lookup[0].str = "PROBLEMS";
	lookup[0].f = &Harl::problems;
	lookup[1].str = "DEBUG";
	lookup[1].f = &Harl::debug;
	lookup[2].str = "INFO";
	lookup[2].f = &Harl::info;
	lookup[3].str = "WARNING";
	lookup[3].f = &Harl::warning;
	lookup[4].str = "ERROR";
	lookup[4].f = &Harl::error;
}

void	Harl::problems()
{
	std::cout << "[ Probably complaining about insignificant problems ]"
	<< std::endl << std::endl;
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
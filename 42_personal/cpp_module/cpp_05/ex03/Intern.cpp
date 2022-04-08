/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:09:56 by sna               #+#    #+#             */
/*   Updated: 2022/04/08 17:11:35 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{

}

Intern::Intern(const Intern& obj)
{
	static_cast<void>(obj);
}

Intern::~Intern()
{

}

Intern& Intern::operator=(const Intern& obj)
{
	static_cast<void>(obj);
	return (*this);
}

Form*	Intern::makeForm(std::string name, std::string target)
{
	std::string name_Arr[3] = {
		"ShrubberyCreationForm",
		"RobotomyRequestForm",
		"PresidentialPardonForm"
	};

	try
	{
		for (int i = 0; i < 3; i++)
		{
			if (name == name_Arr[i])
			{
				std::cout << "Intern create form : " << name << std::endl;
				switch (i)
				{
					case 0:
						return new ShrubberyCreationForm(target);
						break;
					case 1:
						return new RobotomyRequestForm(target);
						break;
					case 2:
						return new PresidentialPardonForm(target);
						break;
				}
			}
		}
		throw Intern::UnknownFormException();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Intern can't create Form " << name << " because " << e.what() << std::endl;
		return (NULL);
	}
}

const char* Intern::UnknownFormException::what(void) const throw()
{
	return ("Unknown Form Name exception.");
}
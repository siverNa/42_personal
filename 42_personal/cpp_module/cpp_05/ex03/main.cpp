/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:12:28 by sna               #+#    #+#             */
/*   Updated: 2022/04/08 17:25:49 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"

int main(void)
{

	Intern intern1;
	Form *receive;
	Bureaucrat baltan("baltan", 3);

	receive = intern1.makeForm("PresidentialPardonForm", "yasuo");
	intern1.makeForm("WrongForm", "yasuo");

	std::cout << std::endl;
	std::cout << "FormName : " << receive->getFormName() << std::endl;
	std::cout << "FormTarget : " << receive->getTarget() << std::endl;
	std::cout << *receive << std::endl;

	std::cout << std::endl;
	std::cout << baltan << std::endl;

	std::cout << std::endl;
	baltan.signForm(*receive);

	std::cout << std::endl;
	baltan.executeForm(*receive);

	delete receive;
	
	return (0);
}
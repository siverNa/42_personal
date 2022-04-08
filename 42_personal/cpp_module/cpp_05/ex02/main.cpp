/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:12:28 by sna               #+#    #+#             */
/*   Updated: 2022/04/08 15:30:15 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	try
	{
		Bureaucrat jucy("jucy", 5);
		ShrubberyCreationForm tree("mjuni");
		RobotomyRequestForm robot("rami");
		PresidentialPardonForm Presi("hanti");

		//사원 등급 및 폼 정보 출력
		std::cout << std::endl;
		std::cout << jucy << std::endl;
		std::cout << tree << std::endl;
		std::cout << robot << std::endl;
		std::cout << Presi << std::endl;

		//각각의 폼에 sign 작업
		std::cout << std::endl;
		tree.beSigned(jucy);
		robot.beSigned(jucy);
		Presi.beSigned(jucy);

		//sing이 되어있는 지 확인
		std::cout << std::endl;
		jucy.signForm(tree);
		jucy.signForm(robot);
		jucy.signForm(Presi);

		std::cout << std::endl;
		// tree.execute(jucy);
		// robot.execute(jucy);
		// Presi.execute(jucy);
		jucy.executeForm(tree);
		jucy.executeForm(robot);
		jucy.executeForm(Presi);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
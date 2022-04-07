/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:12:28 by sna               #+#    #+#             */
/*   Updated: 2022/04/08 01:29:09 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	try
	{
		Bureaucrat jucy("jucy", 5);
		ShrubberyCreationForm tree("mjuni");

		//사원 등급 및 폼 정보 출력
		std::cout << std::endl;
		std::cout << jucy << std::endl;
		std::cout << tree << std::endl;

		//각각의 폼에 sign 작업
		std::cout << std::endl;
		tree.beSigned(jucy);

		//sing이 되어있는 지 확인
		std::cout << std::endl;
		jucy.signForm(tree);

		std::cout << std::endl;
		tree.execute(jucy);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}
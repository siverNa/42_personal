/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:12:28 by sna               #+#    #+#             */
/*   Updated: 2022/04/08 17:36:03 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat lol("lol", 5);

	try
	{
		lol.incrementGrade();
		std::cout << lol << std::endl;
		lol.incrementGrade();
		std::cout << lol << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	try
	{
		Form A("A", 5, 5);
		Form B("B", 1, 1);
		lol.signForm(A);
		lol.signForm(B);
		std::cout << A << std::endl;
		std::cout << B << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

}
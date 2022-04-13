/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:12:58 by sna               #+#    #+#             */
/*   Updated: 2022/04/13 15:30:35 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void)
{
	std::cout << "====================== test1 =====================" << std::endl;
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << "====================== test2 =====================" << std::endl;
	Span sp2(9);
	std::vector<int> temp;
	for (int i = 0; i < 9; i++)
		temp.push_back(i + 1);

	sp2.addNumber(temp.begin(), temp.end());
	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;

	try
	{
		Span sp2_2(9);

		sp2_2.addNumber(12);
		sp2_2.addNumber(15);
		std::vector<int> temp2;
		for (int i = 0; i < 9; i++)
			temp2.push_back(i + 1);

		sp2_2.addNumber(temp2.begin(), temp2.end());
		std::cout << sp2_2.shortestSpan() << std::endl;
		std::cout << sp2_2.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	

	std::cout << "====================== test3 =====================" << std::endl;
	Span sp3 = Span(10000);

	for (int i = -5000; i <= 4999; i++)
		sp3.addNumber(i);
	std::cout << sp3.shortestSpan() << std::endl;
	std::cout << sp3.longestSpan() << std::endl;

	std::cout << "====================== test4 =====================" << std::endl;
	Span sp4 = Span(5);
	sp4.addNumber(-1);
	sp4.addNumber(-3);
	sp4.addNumber(-12);
	sp4.addNumber(-6);
	sp4.addNumber(-8);
	std::cout << sp4.shortestSpan() << std::endl;
	std::cout << sp4.longestSpan() << std::endl;

	std::cout << "====================== test5 =====================" << std::endl;
	try
	{
		Span sp5 = Span(0);
		sp5.addNumber(1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Span sp6 = Span(1);
		sp6.addNumber(1);
		sp6.addNumber(2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "====================== test6 =====================" << std::endl;
	try
	{
		Span sp7 = Span(1);
		sp7.addNumber(2);
		std::cout << sp7.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Span sp8 = Span(0);
		std::cout << sp8.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return (0);
}
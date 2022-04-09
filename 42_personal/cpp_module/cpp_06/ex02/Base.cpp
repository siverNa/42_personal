/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 21:27:56 by sna               #+#    #+#             */
/*   Updated: 2022/04/10 00:50:57 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base * generate(void)
{
	int value;
	Base *base_p;

	std::srand(static_cast<unsigned int>(std::time(0)));
	value = std::rand() % 3;
	if (value == 0)
		base_p = new A;
	else if (value == 1)
		base_p = new B;
	else if (value == 2)
		base_p = new C;
	return (base_p);
}

/*
** 포인터에 dynamic_cast<> 하기
** 포인터의 경우 casting 에 실패할 경우 NULL 반환
*/
void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

/*
** 레퍼런스에 dynamic_cast<>하기
** 레퍼런스의 경우 예외를 throw
*/
void identify(Base& p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch(const std::exception& e)
	{
	}

	try
	{
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
	}
	catch(const std::exception& e)
	{
	}

	try
	{
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl;
	}
	catch(const std::exception& e)
	{
	}
}
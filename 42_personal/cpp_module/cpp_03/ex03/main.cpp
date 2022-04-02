/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:52:19 by sna               #+#    #+#             */
/*   Updated: 2022/04/02 17:54:51 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"

/*
** 생성자 호출 순서 : 부모 생성자 -> 자식 생성자
** 소멸자 호출 순서 : 자식 소멸자 -> 부모 소멸자
*/
int main(void)
{
	FragTrap a("a");
	ScavTrap b("b");
	ClapTrap c("c");

	std::cout << std::endl;
	a.attack("b");
	b.takeDamage(a.getAttack());

	std::cout << std::endl;
	b.attack("a");
	a.takeDamage(b.getAttack());

	std::cout << std::endl;
	a.attack("b");
	b.takeDamage(a.getAttack());

	std::cout << std::endl;
	b.attack("a");
	a.takeDamage(b.getAttack());

	std::cout << std::endl;
	c.attack("a");
	a.takeDamage(c.getAttack());

	std::cout << std::endl;
	a.attack("c");
	c.takeDamage(a.getAttack());

	std::cout << std::endl;
	c.attack("a");
	a.takeDamage(c.getAttack());

	std::cout << std::endl;
	b.guardGate();

	std::cout << std::endl;
	a.highFivesGuys();

	return (0);
}
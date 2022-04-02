/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 15:24:22 by sna               #+#    #+#             */
/*   Updated: 2022/04/02 16:22:16 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/*
** 생성자 호출 순서 : 부모 생성자 -> 자식 생성자
** 소멸자 호출 순서 : 자식 소멸자 -> 부모 소멸자
*/
int main(void)
{
    ScavTrap a("a");
    ScavTrap b("b");

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
    a.guardGate();

    std::cout << std::endl;
    
    return (0);
}
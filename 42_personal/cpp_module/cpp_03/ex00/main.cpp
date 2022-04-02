/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 14:45:28 by sna               #+#    #+#             */
/*   Updated: 2022/04/02 14:49:35 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/*
** 객체가 생성될 때, 
*/

int main(void)
{
    ClapTrap a("a");
    ClapTrap b("b");
    ClapTrap c("c");

    std::cout << std::endl;
    a.attack("b");
    b.takeDamage(a.getAttack());
    std::cout << std::endl;
    b.attack("a");
    a.takeDamage(b.getAttack());
    std::cout << std::endl;
    c.attack("b");
    b.takeDamage(c.getAttack());
    std::cout << std::endl;
    a.beRepaired(25);
    std::cout << std::endl;
    
    return (0);
}
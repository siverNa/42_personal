/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 01:16:08 by sna               #+#    #+#             */
/*   Updated: 2022/03/27 01:27:41 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie *zombie1;
	Zombie *zombie2;

	zombie1 = new Zombie("heap zombie1");
	zombie2 = new Zombie("heap zombie2");
	randomChump("stack zombie3");

	zombie1->announce();
	zombie2->announce();

	delete zombie1;
	delete zombie2;

	return (0);
}
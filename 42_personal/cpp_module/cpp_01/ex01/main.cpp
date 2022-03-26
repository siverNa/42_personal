/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 01:52:02 by sna               #+#    #+#             */
/*   Updated: 2022/03/27 01:55:34 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie *zombie_horde;
	int		N;

	N = 3;
	zombie_horde = zombieHorde(N, "forHorde");
	
	for (int i = 0; i < N; i++)
		zombie_horde->announce();
	
	delete[] zombie_horde;

	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 01:40:16 by sna               #+#    #+#             */
/*   Updated: 2022/03/27 02:02:24 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
** N개의 좀비 객체를 할당하고, 첫 번째 포인터를 반환
** new Zombie[N] 을 통해 한번에 할당
** 각각 이름을 부여 및 초기화를 위해 setter 사용
*/
Zombie*	zombieHorde(int N, std::string name)
{
	if (N <= 0)
		return (NULL);
	
	Zombie *zombie_horde = new Zombie[N];
	
	for (int i = 0; i < N; i++)
		zombie_horde[i].setName(name);
	
	return (zombie_horde);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 00:48:39 by sna               #+#    #+#             */
/*   Updated: 2022/03/27 01:46:44 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//생성자
Zombie::Zombie(void)
{
}

//소멸자
Zombie::~Zombie(void)
{
	std::cout << _name << " is died" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << _name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

//외부에서 접근할 수 없으므로, 우회-접근-수정을 위한 setter 함수 사용
void	Zombie::setName(std::string name)
{
	_name = name;
}
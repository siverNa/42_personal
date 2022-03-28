/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:50:03 by sna               #+#    #+#             */
/*   Updated: 2022/03/28 17:09:16 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void)
{
}

Weapon::~Weapon(void)
{
}

Weapon::Weapon(std::string type)
{
	_type = type;
}

void Weapon::setType(std::string type)
{
	_type = type;
}

const std::string &Weapon::getType(void)
{
	return (_type);
}
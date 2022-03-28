/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:52:10 by sna               #+#    #+#             */
/*   Updated: 2022/03/28 17:08:50 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanA {
 private:
	std::string _name;
	Weapon &_weapon;
 public:
	HumanA(std::string name, Weapon& weapon);
	~HumanA(void);
	void	attack(void);
};

#endif
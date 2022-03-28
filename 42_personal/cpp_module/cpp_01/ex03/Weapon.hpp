/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:49:51 by sna               #+#    #+#             */
/*   Updated: 2022/03/28 17:09:05 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon {
 private:
	std::string _type;
 public:
	Weapon(void);
	~Weapon(void);
	Weapon(std::string type);
	void	setType(std::string type);
	const	std::string &getType(void);
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 01:37:56 by sna               #+#    #+#             */
/*   Updated: 2022/03/27 01:44:03 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie {
 private:
	std::string	_name;
 public:
	Zombie(void);
	~Zombie(void);
	void	announce(void);
	void	setName(std::string name);
};

Zombie*	zombieHorde(int N, std::string name);

#endif
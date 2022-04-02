/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:44:31 by sna               #+#    #+#             */
/*   Updated: 2022/04/02 14:44:55 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

# define RED	"\033[0;31m"
# define GREEN	"\033[0;32m"
# define YELLOW	"\033[0;33m"
# define PURPLE	"\033[0;35m"
# define RESET	"\033[0m"


class ClapTrap {
 private:
	std::string		_name;
	int				_hit;
	unsigned int	_energy;
	unsigned int	_attack;
 public:
	ClapTrap(void);
	ClapTrap(std::string name);

	ClapTrap(const ClapTrap& obj);
	~ClapTrap(void);
	ClapTrap& operator=(const ClapTrap& obj);

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	unsigned int	getAttack(void) const;
};

#endif
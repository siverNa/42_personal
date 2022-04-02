/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 15:26:01 by sna               #+#    #+#             */
/*   Updated: 2022/04/02 16:15:18 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap {
 private:
	bool _guardMode;
 public:
	ScavTrap(void);
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap& obj);
	~ScavTrap(void);
	ScavTrap& operator=(const ScavTrap& obj);

	virtual void	attack(const std::string& target);
	void	guardGate(void);
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:53:08 by sna               #+#    #+#             */
/*   Updated: 2022/04/02 19:58:44 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap {
 private:
	bool _guardMode;
 public:
	ScavTrap(void);
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap& obj);
	virtual ~ScavTrap(void);
	ScavTrap& operator=(const ScavTrap& obj);

	virtual void	attack(const std::string& target);
	void	guardGate(void);
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 17:05:38 by sna               #+#    #+#             */
/*   Updated: 2022/04/02 17:11:19 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap: public ClapTrap {
 private:
 public:
	FragTrap(void);
	FragTrap(std::string name);
	FragTrap(const FragTrap& obj);
	~FragTrap(void);
	FragTrap& operator=(const FragTrap& obj);

	void	highFivesGuys(void);
};

#endif
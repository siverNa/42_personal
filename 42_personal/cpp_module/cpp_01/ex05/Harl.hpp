/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 00:17:51 by sna               #+#    #+#             */
/*   Updated: 2022/03/29 22:51:17 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

class Harl {
	typedef struct	s_lookup
	{
		std::string	str;
		void		(Harl::*f)(void);
	}				t_lookup;
 private:
	t_lookup lookup[4];
	void	init(void);
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
 public:
	Harl(void);
	~Harl(void);
	void	complain(std::string level);
};

#endif
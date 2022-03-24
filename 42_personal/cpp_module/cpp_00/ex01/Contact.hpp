/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:53:20 by sna               #+#    #+#             */
/*   Updated: 2022/03/25 00:41:30 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <string>

class Contact {
 private:
	int					_index;
	static std::string	_field_names[5];
	std::string			_information[5];
 public:
	Contact();
	~Contact();
	bool	set_information(int index);
	void	display_info(void);
	void	display(void);
};

#endif
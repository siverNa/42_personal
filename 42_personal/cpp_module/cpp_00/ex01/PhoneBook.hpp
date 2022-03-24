/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:22:59 by sna               #+#    #+#             */
/*   Updated: 2022/03/25 00:54:45 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <limits>
# include "Contact.hpp"

class PhoneBook {
 private:
	Contact _contact[8];
	int		_count;
 public:
	PhoneBook();
	~PhoneBook();
	void	show_main(void);
	void	add_contact(int idx);
	void	search_contact(void);
	void	show_search_info(void);
};

#endif
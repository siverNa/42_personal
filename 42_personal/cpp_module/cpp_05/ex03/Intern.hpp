/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:36:33 by sna               #+#    #+#             */
/*   Updated: 2022/04/08 17:18:21 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "Form.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern {
 private:
 public:
	Intern();
	Intern(const Intern& obj);
	virtual ~Intern();
	Intern& operator=(const Intern& obj);

	Form*	makeForm(std::string name, std::string target);

	class UnknownFormException : public std::exception {
		public:
			const char *what(void) const throw();
	};
};

#endif
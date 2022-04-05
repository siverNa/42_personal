/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:28:26 by sna               #+#    #+#             */
/*   Updated: 2022/04/05 20:56:19 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat {
 private:
	const std::string	_name;
	int					_grade;
 public:
	Bureaucrat(void);
	Bureaucrat(const std::string name, int grade);
	Bureaucrat(const Bureaucrat& obj);
	~Bureaucrat(void);
	Bureaucrat& operator=(const Bureaucrat& obj);

	std::string	getName(void) const;
	unsigned int getGrade(void) const;
	void incrementGrade(void);
	void decrementGrade(void);

	class GradeTooHighException: public std::exception {
		public:
			const char *what(void) const throw();
	};

	class GradeTooLowException: public std::exception {
		public:
			const char *what(void) const throw();
	};
	
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bur);

#endif
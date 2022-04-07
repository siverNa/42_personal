/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 23:33:20 by sna               #+#    #+#             */
/*   Updated: 2022/04/07 16:27:16 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
 private:
	const std::string _formName;
	bool _signed;//sign 상태
	const int _signGrade;//사인하는 데 요구되는 grade
	const int _execGrade;//실행하는 데 요구되는 grade
 public:
	Form(void);
	Form(const std::string name, int signgrade, int execgrade);
	Form(const Form& obj);
	~Form(void);
	Form& operator=(const Form& obj);

	void	beSigned(const Bureaucrat& bur);
	
	std::string	getFormName(void) const;
	bool getSigned(void) const;
	int getSignGrade(void) const;
	int getExecGrade(void) const;

	class GradeTooHighException: public std::exception {
		public:
			const char *what(void) const throw();
	};

	class GradeTooLowException: public std::exception {
		public:
			const char *what(void) const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
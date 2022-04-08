/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 23:33:20 by sna               #+#    #+#             */
/*   Updated: 2022/04/08 01:30:06 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
 private:
	const std::string _target;//ex02에 추가된 변수
	const std::string _formName;
	bool _signed;//sign 상태
	const int _signGrade;//사인하는 데 요구되는 grade
	const int _execGrade;//실행하는 데 요구되는 grade
 public:
	Form(void);
	Form(const std::string target, const std::string name, int signgrade, int execgrade);
	Form(const Form& obj);
	virtual ~Form(void);
	Form& operator=(const Form& obj);

	void	beSigned(const Bureaucrat& bur);
	
	std::string	getFormName(void) const;
	bool getSigned(void) const;
	int getSignGrade(void) const;
	int getExecGrade(void) const;

	//ex02에서 추가한 함수
	std::string getTarget(void) const;

	//하위 3개 클래스에서 overriding할 수 있도록 순수 가상함수로 선언
	virtual void execute(Bureaucrat const & executor) const = 0;

	class GradeTooHighException: public std::exception {
		public:
			const char *what(void) const throw();
	};

	class GradeTooLowException: public std::exception {
		public:
			const char *what(void) const throw();
	};

	//추가된 예외들
	class IsNotSignedException: public std::exception {
		public:
			const char *what(void) const throw();
	};

	class ExecGradeTooLowException: public std::exception {
		public:
			const char *what(void) const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
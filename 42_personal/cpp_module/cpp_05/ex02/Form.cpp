/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 23:36:21 by sna               #+#    #+#             */
/*   Updated: 2022/04/08 17:46:06 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _target(""), _formName(""), _signGrade(0), _execGrade(0)
{
	_signed = false;
}

Form::Form(const std::string target, const std::string name, int signgrade, int execgrade) : _target(target), _formName(name), _signGrade(signgrade), _execGrade(execgrade)
{
	if (_signGrade < 1 || _execGrade < 1)
		throw Form::GradeTooHighException();
	else if (_signGrade > 150 || _execGrade > 150)
		throw Form::GradeTooLowException();
	_signed = false;
}

Form::Form(const Form& obj) : _target(obj.getTarget()), _formName(obj.getFormName()), _signGrade(obj.getSignGrade()), _execGrade(obj.getExecGrade())
{
	if (_signGrade < 1 || _execGrade < 1)
		throw Form::GradeTooHighException();
	else if (_signGrade > 150 || _execGrade > 150)
		throw Form::GradeTooLowException();
	_signed = obj.getSigned();
}

Form::~Form()
{

}

Form& Form::operator=(const Form& obj)
{
	_signed = obj.getSigned();
	return (*this);
}

void	Form::beSigned(const Bureaucrat& bur)
{
	if (bur.getGrade() <= _signGrade)
		_signed = true;
	else
		throw Form::GradeTooLowException();
}
	
std::string	Form::getFormName(void) const
{
	return (_formName);
}

bool Form::getSigned(void) const
{
	return (_signed);
}

int Form::getSignGrade(void) const
{
	return (_signGrade);
}

int Form::getExecGrade(void) const
{
	return (_execGrade);
}

std::string Form::getTarget(void) const
{
	return (_target);
}

const char* Form::GradeTooHighException::what(void) const throw()
{
	return ("Form Grade too high exception.");
}

const char* Form::GradeTooLowException::what(void) const throw()
{
	return ("Form Grade too low exception.");
}

const char* Form::IsNotSignedException::what(void) const throw()
{
	return ("Not Singed exception.");
}

const char* Form::ExecGradeTooLowException::what(void) const throw()
{
	return ("Exec Grade too low exception.");
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << form.getFormName() << ", target : [ " << form.getTarget()
	<< " ] signGrade : [ " << form.getSignGrade()
	<< " ] , execGrade : [ " << form.getExecGrade();
	if (form.getSigned())
		os << " ], signed.";
	else
		os << " ] , not signed.";
	return (os);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:30:18 by sna               #+#    #+#             */
/*   Updated: 2022/04/07 18:30:29 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void)
{
	_grade = 0;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj) : _name(obj.getName())
{
	if (obj.getGrade() < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (obj.getGrade() > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = obj.getGrade();
}

Bureaucrat::~Bureaucrat(void)
{

}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj)
{
	_grade = obj.getGrade();
	return (*this);
}

std::string	Bureaucrat::getName(void) const
{
	return (_name);
}

int Bureaucrat::getGrade(void) const
{
	return (_grade);
}

void Bureaucrat::incrementGrade(void)
{
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	--_grade;
}

void Bureaucrat::decrementGrade(void)
{
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	++_grade;
}

//추가된 함수
void Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getFormName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->getName() << " couldn’t sign " << form.getFormName() << " because " << e.what() << std::endl;
	}
	
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Bur Grade too high exception.");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Bur Grade too low exception.");
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bur)
{
	os << bur.getName() << ", bureaucrat grade " << bur.getGrade() << ".";
	return (os);
}
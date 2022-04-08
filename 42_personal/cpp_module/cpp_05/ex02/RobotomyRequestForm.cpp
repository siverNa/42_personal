/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:16:09 by sna               #+#    #+#             */
/*   Updated: 2022/04/08 14:34:21 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("none", "RobotomyRequestForm", 72, 45)
{

}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : Form(target, "RobotomyRequestForm", 72, 45)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj) : Form(obj)
{

}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj)
{
	this->Form::operator=(obj);
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (getSigned() == false)
		throw IsNotSignedException();
	if (getExecGrade() < executor.getGrade())
		throw ExecGradeTooLowException();
	
	/*
	** static_cast : 원하는 자료형으로 형변환
	** 시스템 클럭을 사용하면 사용자가 프로그램을 실행할 때마다 시간이 달라진다.
	** 이 시간 값을 시드로 사용하면 프로그램이 실행될 때마다 다른 시퀀스 숫자를 생성한다.
	** C++에는 1970년 1월 1일 자정 이후의 초 수를 반환하는 time()이라는 함수가 있다.
	** 이를 사용하려면 <ctime> 헤더를 포함하고 srand()를 time(0) 호출로 초기화해야 한다.
	*/
	std::srand(static_cast<unsigned int>(std::time(0)));
	std::cout << "Drrrrrrrrrrrr...." << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << getTarget() << " has been robotomized successfully!" << std::endl;
	else
		std::cout << getTarget() << " failed to be robotomized..." << std::endl;
}
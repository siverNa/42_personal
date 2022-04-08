/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 20:59:31 by sna               #+#    #+#             */
/*   Updated: 2022/04/08 17:31:45 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		//정상 선언
		Bureaucrat employee("yohan", 10);
		std::cout << employee << std::endl;

		//정상 증가
		std::cout << std::endl;
		Bureaucrat employee2("nemo", 2);
		std::cout << "increase before : " << employee2 << std::endl;
		employee2.incrementGrade();
		std::cout << "increase after : " << employee2 << std::endl;

		//정상 감소
		std::cout << std::endl;
		Bureaucrat employee3("yone", 149);
		std::cout << "decrease before : " << employee3 << std::endl;
		employee3.decrementGrade();
		std::cout << "decrease after : " << employee3 << std::endl;
		
		//grade를 너무 높임
		// std::cout << std::endl;
		// Bureaucrat employee4("hans", 1);
		// std::cout << "increase before : " << employee4 << std::endl;
		// employee4.incrementGrade();
		// std::cout << "increase after : " << employee4 << std::endl;

		//grade를 너무 낮춤
		// std::cout << std::endl;
		// Bureaucrat employee5("hans", 150);
		// std::cout << "decrease before : " << employee5 << std::endl;
		// employee5.decrementGrade();
		// std::cout << "decrease after : " << employee5 << std::endl;

		//초기 설정시 grade가 너무 높음
		// std::cout << std::endl;
		// Bureaucrat employee6("yasuo", -1);
		// std::cout << employee6 << std::endl;

		//초기화시 grade가 너무 낮음
		// std::cout << std::endl;
		// Bureaucrat employee7("vein", 200);
		// std::cout << employee7 << std::endl;
	}
	catch(std::exception & e)//throw 에 설정된 에러문 출력
	{
		std::cerr << e.what() << std::endl;
	}
	
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 21:12:12 by sna               #+#    #+#             */
/*   Updated: 2022/03/27 21:24:00 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** l-value : 메모리 주소를 가진 객체 - 포인터
** r-value : 메모리 주소가 없고, 표현식 범위에만 있는 임시 값 - 레퍼런스
*/
#include <iostream>
#include <string>

int main(void)
{
	std::string brain_str = "HI THIS IS BRAIN";
	std::string *stringPTR = &brain_str;
	std::string& stringREF = brain_str;

	std::cout << "brain_str memory address : " << &brain_str << std::endl;
	std::cout << "stringPTR memory address : " << stringPTR << std::endl;
	std::cout << "stringREF memory address : " << &stringREF << std::endl;

	std::cout << "brain_str value : " << brain_str << std::endl;
	std::cout << "stringPTR value : " << *stringPTR << std::endl;
	std::cout << "stringREF value : " << stringREF << std::endl;

	return (0);
}
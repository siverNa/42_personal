/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 15:14:26 by sna               #+#    #+#             */
/*   Updated: 2022/04/03 16:50:30 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

/*
** c++의 다형성
** Polymorphism(다형성) 이란 여러 개의 서로 다른 객체가 동일한 기능을 
** 서로 다른 방법으로 처리할 수 있는 기능을 의미한다. 
** - 가상 함수 : 부모 클래스와 자식 클래스에 동일한 이름의 함수의 다른 작동
** - 함수 템플릿 : 동일한 이름의 함수가 다양한 자료형을 처리
** - 함수 오버로드 : 동일한 이름의 함수가 다른 작동
** - 연산자 오버로드 : 한 가지 연산자가 다양한 작동
*/

class Animal {
 private:

 protected:
	std::string _type;

 public:
	Animal(void);
	Animal(const Animal& obj);
	virtual ~Animal(void);//상속받은 하위 클래스의 소멸자가 작동할 수 있도록 가상 소멸자로 만들기
	Animal& operator=(const Animal& obj);

	virtual void makeSound(void) const;//Virtual Function이란 자식 클래스에서 재정의 할 수 있는 멤버 함수이다.
	std::string getType(void) const;
	void		setType(const std::string& type);
};

#endif
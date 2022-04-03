/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 15:14:26 by sna               #+#    #+#             */
/*   Updated: 2022/04/03 21:03:08 by sna              ###   ########.fr       */
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

	//순수 가상 함수, 하위 클래스에서 꼭 재정의해야함
	//추상 클래스는 하나 이상의 순수 가상 함수를 포함하고 있는 클래스를 말함
	//이 때문에 .cpp 에서 makeSound 에 대한 동작이 정의가 안되어있음
	virtual void makeSound(void) const = 0;
	std::string getType(void) const;
	void		setType(const std::string& type);
};

#endif
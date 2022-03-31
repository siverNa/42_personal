/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 00:50:43 by sna               #+#    #+#             */
/*   Updated: 2022/03/31 23:20:26 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//생성자
Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

/*
** 정수를 고정 소수점으로 바꿀 경우,
** 변환하고자 하는 값이 num 이면 num << 8 을 수행하면됨
*/
Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	_value = num << _bit;
}

/*
** 실수를 고정 소수점으로 바꿀 경우,
** float 같은 부동 소수점의 경우 '<<' 같은 쉬프트 연산이 불가능하므로 우회해서 표현해야함
** 또한 고정 소수점으로 저장할 _value 가 int형이므로, 일부 데이터가 누락될 수 있음
** 그러므로 비교적 정확한 변환을 위해, roundf 을 통해 반올림함
** roundf(num * (1 << 8))
*/
Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(num * (1 << _bit));
}

/*
** 복사 생성자
** 자기 자신을 대상으로, operator= 을 호출, 그 인자로 원본 객체 f를 넣는다는 의미
*/
Fixed::Fixed(const Fixed& f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;//연산자 오버로딩 실행 부분
}

/*
** 연산자 오버로딩
** 객체의 값(_value) 를 받아서 집어넣어줌
*/
Fixed& Fixed::operator=(const Fixed& f)
{
	std::cout << "Copy assignment operator called" << std::endl;
	_value = f._value;
	return (*this);
}

//소멸자
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void	Fixed::setRawBits(int const raw)
{
	_value = raw;
}

/*
** 고정 소수점을 실수로 바꿀 경우,
** Fixed 클래스에 저장되어있던 고정 소수점 _value 를 float로 형변환하여 부동 소수점으로 바꾸고
** 고정 소수점을 표현하기 위해 << 연산한 값을 다시 되돌려야한다
** float(_value) / (1 << 8)
*/
float	Fixed::toFloat(void) const
{
	return ((float)_value / (1 << _bit));
}

/*
** 고정 소수점을 정수로 바꿀 경우,
** 기존 값을 다시 원위치 시키면된다. 즉, _value >> 8
*/
int		Fixed::toInt(void) const
{
	return (_value >> _bit);
}

std::ostream& operator<<(std::ostream& o, const Fixed& f)
{
	o << f.toFloat();
	return (o);
}
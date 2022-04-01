/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 23:45:01 by sna               #+#    #+#             */
/*   Updated: 2022/04/01 00:48:43 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>//roundf

class Fixed {
 private:
	int					_value;//고정 소숫점 숫자값을 저장
	const static int	_bit = 8;//fractional bits(소수 비트) 를 저장
 public:
	Fixed(void);
	Fixed(const int num);//constant int 를 받는 생성자
	Fixed(const float num);//constant floating-point 를 받는 생성자.
	Fixed(const Fixed& f);
	Fixed& operator=(const Fixed& f);
	~Fixed(void);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;//고정 소수점 값을 부동 소수점 값으로
	int		toInt(void) const;//고정 소수점 값을 정수 값으로

	bool	operator>(const Fixed& f);
	bool	operator<(const Fixed& f);
	bool	operator>=(const Fixed& f);
	bool	operator<=(const Fixed& f);
	bool	operator==(const Fixed& f);
	bool	operator!=(const Fixed& f);

	Fixed	operator+(const Fixed& f);
	Fixed	operator-(const Fixed& f);
	Fixed	operator*(const Fixed& f);
	Fixed	operator/(const Fixed& f);

	Fixed&	operator++(void);//전위 증가연산자
	Fixed	operator++(int);//후위 증가연산자
	Fixed&	operator--(void);//전위 감소연산자
	Fixed	operator--(int);//후위 감소연산자

	static	Fixed&			min(Fixed& left, Fixed& right);
	static	const	Fixed& 	min(const Fixed& left, const Fixed& right);
	static	Fixed&			max(Fixed& left, Fixed& right);
	static	const	Fixed&	max(const Fixed& left, const Fixed& right);
};

std::ostream& operator<<(std::ostream& o, const Fixed& f);

#endif
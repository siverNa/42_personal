/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 15:49:37 by sna               #+#    #+#             */
/*   Updated: 2022/04/11 14:39:21 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>
# include <string>

/*
** 함수 템플릿 만들기
** 함수를 만들어 낼때, 함수의 기능은 명확하지만, 자료형을 모호하게 두는 것.
** 자료형이 들어가는 자리를 T가 대신하는데, int, double 등 다 받을 수있음!
** templete 은 헤더파일 내에서 정의해줘야함.
*/
template <typename T>
void swap(T &a, T &b)
{
	T temp;

	temp = a;
	a = b;
	b = temp;
}

template <typename T>
T& min(T &a, T &b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

template <typename T>
T& max(T &a, T &b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

#endif